package com.tu.bzahov.Exceptions;

public class NoStaffException extends Exception {
    @Override
    public String getMessage() {
        return "NoStaffException";
    }
}