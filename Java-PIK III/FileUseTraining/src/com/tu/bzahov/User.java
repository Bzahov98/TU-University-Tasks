package com.tu.bzahov;

import java.io.Serializable;

public class User implements Serializable {
    private final String firstName;
    private final String lastName;


    public User(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }
}
