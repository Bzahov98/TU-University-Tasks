package com.tu.bzahov.Exceptions;

public class CarNotValidException extends Exception {

    @Override
    public String getMessage() {
        return "CarNotValidLicenseException";
    }
}
