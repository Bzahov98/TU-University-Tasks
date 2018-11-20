package com.tu.bzahov.exceptions;

public class EmptySetException extends Throwable {
    @Override
    public String getMessage() {
        return "Empty Set Exception";
    }
}
