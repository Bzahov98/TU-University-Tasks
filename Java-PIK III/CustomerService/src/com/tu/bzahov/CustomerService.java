package com.tu.bzahov;

import java.util.ArrayList;

public class CustomerService {
    private int idOfDesk;
    private ArrayList<PropertyInquiry> serviceList;
    private Employee employeeOnDesk;
    private int currentInputNum;

    public CustomerService(int idOfDesk) {
        this.idOfDesk = idOfDesk;
        this.serviceList = new ArrayList<>();
    }

    public CustomerService(int idOfDesk, Employee employeeOnDesk, int currentInputNum) {
        this.idOfDesk = idOfDesk;
        this.serviceList = new ArrayList<>();
        this.employeeOnDesk = employeeOnDesk;
        this.currentInputNum = currentInputNum;
    }
    public static int AddInquiry(PropertyInquiry newProperty) throws NullPointerException{
        if (newProperty==null) throw new NullPointerException();
        //TODO:
        return 0;

    }
}
