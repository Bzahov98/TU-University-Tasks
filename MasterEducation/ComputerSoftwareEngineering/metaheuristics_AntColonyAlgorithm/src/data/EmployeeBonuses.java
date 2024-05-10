package data;

import java.util.List;

public class EmployeeBonuses {
    private String employeeId;
    private int grossBonus;
    private String date;
    private int historicalAverageBonus;

    public EmployeeBonuses(String employeeId, int grossBonus, String date, int historicalAverageBonus) {
        this.employeeId = employeeId;
        this.grossBonus = grossBonus;
        this.date = date;
        this.historicalAverageBonus = historicalAverageBonus;
/*        this.deviation = deviation*/;
    }

    @Override
    public String toString() {
        return "ΕΓΗ: "+employeeId + "\nБрутен бонус: " + grossBonus + "\nДата (уууу-мм-дд): "
                + date + "\nИсторически среден бонус: " + historicalAverageBonus;
    }

    public String getEmployeeId() {
        return employeeId;
    }
    public void setEmployeeId(String employeeId) {
        this.employeeId = employeeId;
    }

    public int getGrossBonus() {
        return grossBonus;
    }

    public void setGrossBonus(int grossBonus) {
        this.grossBonus = grossBonus;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public int getHistoricalAverageBonus() {
        return historicalAverageBonus;
    }

    public void setHistoricalAverageBonus(int historicalAverageBonus) {
        this.historicalAverageBonus = historicalAverageBonus;
    }
    public int getIndexInList(List<EmployeeBonuses> employeeList) {
        return employeeList.indexOf(this);
    }
}