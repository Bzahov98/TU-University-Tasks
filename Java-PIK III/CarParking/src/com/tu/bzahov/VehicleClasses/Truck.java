package com.tu.bzahov.VehicleClasses;

import com.tu.bzahov.Exceptions.CarNotValidException;
import com.tu.bzahov.VehicleClasses.MPS;

public class Truck extends MPS {
    private int trailerSize;

    public Truck(String license, String model, int year, int trailerSize) throws CarNotValidException {
        super(license, model, year);
        this.trailerSize = trailerSize;
    }
    public int getSize() {
        return trailerSize;
    }
}
