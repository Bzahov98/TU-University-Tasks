package com.tu.bzahov;


public class CustomerServiceSofia extends CustomerService {
    protected final static String FIXED_TOWN= "Sofia";
    protected String municipality;

    public CustomerServiceSofia(int idOfDesk) {
        super(idOfDesk);
        this.municipality = FIXED_TOWN;
    }

    public static int addInquiry(PropertyInquiry newProperty) throws NullPointerException{
        if (newProperty.getTownName().equals(FIXED_TOWN)) {
            System.out.println("Matching towns");
            CustomerService.addInquiry(newProperty);
        }else System.out.println("Towns don't match");
        //super.addInquiry(newProperty);
        return currentInputNum;
    }

}
