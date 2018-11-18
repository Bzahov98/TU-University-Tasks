package com.tu.bzahov;

import com.tu.bzahov.exception.WrongEgnException;

public class Employee {
    private String name;
    private int idDepartment;
    private long egn;

    public Employee(String name, int idDepartment, long egn) throws WrongEgnException{
        setIdDepartment(idDepartment);
        setName(name);
        setEGN(egn);
    }

    public void setEGN(long egn) throws WrongEgnException {
        int digitsCount = 0;
        while (egn!= 0){
            egn/=10;
            digitsCount++;
        }
        if (digitsCount == 10){
            this.egn = egn;
            return;
        }
        throw new WrongEgnException();
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setIdDepartment(int idDepartment) {
        this.idDepartment = idDepartment;
    }

    public String getName() {
        return name;
    }

    public int getIdDepartment() {
        return idDepartment;
    }

    public long getEgn() {
        return egn;
    }
}
