package com.tu.bzahov.VehicleClasses;

import com.tu.bzahov.Exceptions.CarNotValidException;

public class Car extends MPS {

    public Car(String license, String model, int year) throws CarNotValidException {
        super(license, model, year);
    }

}
