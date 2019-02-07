package com.tu.bzahov.Model;
import java.io.Serializable;

public class Document implements Serializable {
    private String name;
    private double grade;
    private double income;
    private String faculty;
    private boolean isValid;
    private int type;

    public Document(){}

    public Document(String name, double grade, double income, String faculty, boolean isValid, int type) {
        this.name = name;
        this.grade = grade;
        this.income = income;
        this.faculty = faculty;
        this.isValid = isValid;
        this.type = type;
    }

    public void setValid() {
        isValid = true;
    }

    public String getName() {
        return name;
    }

    public double getGrade() {
        return grade;
    }

    public double getIncome() {
        return income;
    }

    public String getFaculty() {
        return faculty;
    }

    public boolean isValid() {
        return isValid;
    }

    public int getType() {
        return type;
    }
}

