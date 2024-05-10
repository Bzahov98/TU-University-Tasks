package algorithm;

import data.EmployeeBonuses;

import java.util.*;

public class AcoAlgorithm {

    private static final double ALPHA = 1.0;  // Parameter for pheromone influence
    private static final double BETA = 1.0;   // Parameter for desirability influence
    private static final double RHO = 0.5;    // Decay factor for pheromone evaporation
    private static final double DELTA_TAU = 0.1; // Pheromone deposit amount by each ant

    public static List<Map.Entry<Integer, EmployeeBonuses>> executeAcoAlgorithm(
            List<EmployeeBonuses> employees,
            int antCount,
            int iterations
    ) {
        List<Map.Entry<Integer, EmployeeBonuses>> deviations = new ArrayList<>();

        // Initialize pheromone trails
        double[][] tau = initPheromoneTrails(employees);

        // Ant movement simulation
        antMovementSimulation(employees, antCount, iterations, tau);

        // Calculate deviation based on final pheromone levels (placeholder)
        // After ant movement simulation
        calculateDeviationOfEmployees(employees, tau, deviations);

        // Sort deviations in descending order
        deviations.sort((o1, o2) -> -o1.getKey().compareTo(o2.getKey()));
        return deviations;
    }

    private static double[][] initPheromoneTrails(List<EmployeeBonuses> employees) {
        // Initialize pheromone trails
        double[][] tau = new double[employees.size()][employees.size()];
        for (int i = 0; i < employees.size(); i++) {
            for (int j = 0; j < employees.size(); j++) {
                tau[i][j] = 0.1; // Initial small pheromone level
            }
        }
        return tau;
    }

    private static void antMovementSimulation(
            List<EmployeeBonuses> employees,
            int antCount,
            int iterations,
            double[][] tau
    ) {
        for (int iter = 0; iter < iterations; iter++) {
            for (int ant = 0; ant < antCount; ant++) {
                List<Integer> visitedEmployees = new ArrayList<>();
                int currentEmployee = new Random().nextInt(employees.size());
                visitedEmployees.add(currentEmployee);

                while (visitedEmployees.size() < employees.size()) {
                    int nextEmployee = selectNextEmployee(employees, visitedEmployees, tau, currentEmployee);
                    visitedEmployees.add(nextEmployee);
                    updatePheromone(currentEmployee, nextEmployee, tau);
                    currentEmployee = nextEmployee;
                }
            }
        }
    }


    private static void calculateDeviationOfEmployees(
            List<EmployeeBonuses> employees,
            double[][] tau,
            List<Map.Entry<Integer, EmployeeBonuses>> deviations
    ) {
        System.out.println("<``````````````````````````````````````````````````>");
        System.out.println("Отклоненията на работниците (ЕГН | Отклонение):");

        for (EmployeeBonuses employee : employees) {
            double totalPheromone = 0.0;
            for (int j = 0; j < employees.size(); j++) {
                if (j != employee.getIndexInList(employees)) { // Avoid self-comparison
                    totalPheromone += tau[j][employee.getIndexInList(employees)];
                }
            }
            int deviation = Math.abs(employee.getGrossBonus() - employee.getHistoricalAverageBonus());
            deviations.add(new AbstractMap.SimpleEntry<>(deviation, employee));
            System.out.println(employee.getEmployeeId() + ", " + deviation); // Consider using totalPheromone
        }
    }

    public static int selectNextEmployee(
            List<EmployeeBonuses> employees, List<Integer> visitedEmployees, double[][] tau,
            int currentEmployee
    ) {
        double[] probabilities = new double[employees.size()];
        double sum = 0.0;

        for (int i = 0; i < employees.size(); i++) {
            if (!visitedEmployees.contains(i)) {
                double eta = calculateDesirability(employees.get(i));  // Implement desirability calculation
                probabilities[i] = Math.pow(tau[currentEmployee][i], ALPHA) * Math.pow(eta, BETA);
                sum += probabilities[i];
            }
        }

        double randomValue = new Random().nextDouble() * sum;
        double currentProbability = 0.0;
        for (int i = 0; i < employees.size(); i++) {
            if (!visitedEmployees.contains(i)) {
                currentProbability += probabilities[i];
                if (currentProbability >= randomValue) {
                    return i;
                }
            }
        }
        return -1; // Should not reach here (indicates potential issues)
    }

    private static double calculateDesirability(EmployeeBonuses employee) {
        int deviation = Math.abs(employee.getGrossBonus() - employee.getHistoricalAverageBonus());
        return 1.0 / deviation;  // Higher desirability for lower deviation
    }

    public static void updatePheromone(int currentEmployee, int nextEmployee, double[][] tau) {
        tau[currentEmployee][nextEmployee] =
                (1 - RHO) * tau[currentEmployee][nextEmployee] + RHO * DELTA_TAU;
    }
}
