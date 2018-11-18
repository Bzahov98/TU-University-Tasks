package com.tu.bzahov;

public class App {

    public static void main(String[] args) {
        try {

            PropertyInquiry propertyInquiry = new PropertyInquiry(1,"Pesho","Gosho","Sofjia");
            CustomerService csOther = new CustomerService(1);
            CustomerServiceSofia csSofia = new CustomerServiceSofia(1);
            System.out.println(csSofia.addInquirySofia(propertyInquiry));
            System.out.println(csSofia.removeInquiry(0));
        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
