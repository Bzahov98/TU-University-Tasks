package com.tu.bzahov.exceptions;

public class MyEventException extends Exception {
    @Override
    public String getMessage() {
        return "Event Exception";
    }
}
