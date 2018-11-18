package com.tu.bzahov;

import com.sun.media.sound.InvalidDataException;

import java.util.ArrayList;

public class CustomerService {
    protected int idOfDesk;
    protected static ArrayList<PropertyInquiry> serviceList = new ArrayList<>();
    protected Employee employeeOnDesk;
    protected static int currentInputNum = 0;

    public CustomerService(int idOfDesk) {
        this.idOfDesk = idOfDesk;
    }

  /*  public CustomerService(int idOfDesk, Employee employeeOnDesk, int currentInputNum) {
        this.idOfDesk = idOfDesk;
        this.serviceList = new ArrayList<>();
        this.employeeOnDesk = employeeOnDesk;
        this.currentInputNum = currentInputNum;
    }*/
    public static int addInquiry(PropertyInquiry newProperty) throws NullPointerException{
        if (newProperty==null) throw new NullPointerException();
        serviceList.add(newProperty);
        currentInputNum++;
        System.out.println("Inquiry "+ currentInputNum + "has been added Successfully");
        return currentInputNum;
    }

    public static int removeInquiry(int indexForDelete) throws InvalidDataException, NullPointerException{
        if (indexForDelete<0 || currentInputNum == 0) throw new InvalidDataException();
        if(serviceList == null) throw new NullPointerException();
        serviceList.remove(indexForDelete);
        System.out.println("Inquiry "+ currentInputNum + "has been removed Successfully");
        currentInputNum--;
        return currentInputNum;
    }

    public Employee getEmployeeOnDesk() {
        return employeeOnDesk;
    }

    public void setEmployeeOnDesk(Employee employeeOnDesk) {
        this.employeeOnDesk = employeeOnDesk;
    }
}
