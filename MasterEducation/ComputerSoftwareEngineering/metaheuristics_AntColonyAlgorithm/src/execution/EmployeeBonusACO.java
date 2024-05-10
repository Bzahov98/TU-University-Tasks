package execution;

import data.EmployeeBonuses;
import data.EmployeeBonusData;

import java.util.List;
import java.util.Map;

import static algorithm.AcoAlgorithm.executeAcoAlgorithm;

public class EmployeeBonusACO {

    public static void main(String[] args) {
        int antCount = 10;  // Number of ants
        int iterations = 20; // Number of iterations

        // Sample employee data (replace with your actual data)
        List<EmployeeBonuses> employees = EmployeeBonusData.initEmployeesData();
        // Deviation result
        List<Map.Entry<Integer, EmployeeBonuses>> deviations =
                executeAcoAlgorithm(employees, antCount, iterations);
        // Print Results
        printResultDeviations(deviations);
    }

    private static void printResultDeviations(List<Map.Entry<Integer, EmployeeBonuses>> deviations) {
        // Print employee with the biggest deviation
        Map.Entry<Integer, EmployeeBonuses> maxDeviation = deviations.get(0);
        System.out.println("\n<``````````````````````````````````````````````````>");
        System.out.println("Работникът с най-голямо отклонение:\n" +
                "----------------------------------");
        System.out.println("Данни на Работник: " + maxDeviation.getValue().toString());
        System.out.println("\n-------------------");
        System.out.println("Отклонение: " + maxDeviation.getKey());
        System.out.println("-------------------");
        System.out.println("\n<``````````````````````````````````````````````````>");
    }
}