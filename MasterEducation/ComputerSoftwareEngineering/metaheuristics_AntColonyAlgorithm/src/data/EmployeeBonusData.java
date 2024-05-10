package data;

import java.util.ArrayList;
import java.util.List;

public class EmployeeBonusData {

    public static List<EmployeeBonuses> initEmployeesData() {
        List<EmployeeBonuses> employees = EmployeeBonusData.createEmployeeTestData();

        System.out.println("Данните за работниците:");
        for (int i = 0; i < employees.size(); i++) {
            EmployeeBonuses employee = employees.get(i);
            System.out.println("--------- "+ i +" ---------");
            System.out.println(employee.toString());
        }
        return employees;
    }

    public static List<EmployeeBonuses> createEmployeeTestData() {
        List<EmployeeBonuses> data = new ArrayList<>();
        data.add(new EmployeeBonuses("1234567889", 333, "2024-01-02", 333));
        data.add(new EmployeeBonuses("1234567890", 333, "2024-01-01", 333));
        data.add(new EmployeeBonuses("1234567891", 222, "2024-02-03", 333));
        data.add(new EmployeeBonuses("1234567892", 333, "2024-03-05", 333));
        data.add(new EmployeeBonuses("1234567893", 111, "2024-04-06", 333));
        data.add(new EmployeeBonuses("1234567894", 333, "2024-05-08", 333));
        data.add(new EmployeeBonuses("1234567895", 1000, "2024-06-09", 333));
        return data;
    }
}