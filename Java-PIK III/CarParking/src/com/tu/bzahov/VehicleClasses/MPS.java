package com.tu.bzahov.VehicleClasses;

import com.tu.bzahov.Exceptions.CarNotValidException;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MPS {
    private String license;
    private String model;
    private int year;
    private final static String LICENSE_EXPRESSION = "^[A-Z]{2}[0-9]{4}[A-Z]{2}@[a-z0-9]{0,10}\\$[0-9]{4}$";


    public MPS(String license, String model, int year) throws CarNotValidException {
        setLicense(license);
        setModel(model);
        setYear(year);
        if( !checkLicence(toString()) ){
            throw new CarNotValidException();
        }
        System.out.println("New vehicle "+ toString() +" has been created");
    }

    @Override
    public String toString(){
       return license + "@" + model + "$" + Integer.toString(year);
    }

    public  boolean checkLicence(String licenceToCheck) {
        Pattern pattern = Pattern.compile(LICENSE_EXPRESSION);
        Matcher matcher = pattern.matcher(licenceToCheck);
        return matcher.matches();
    }

    public String getLicense() {
        return license;
    }

    public void setLicense(String license) {
        this.license = license;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

}
