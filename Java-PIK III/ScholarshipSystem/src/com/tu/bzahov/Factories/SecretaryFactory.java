package com.tu.bzahov.Factories;

import com.tu.bzahov.RolesRunnables.SecretaryRunnable;
import com.tu.bzahov.Server.ServerApp;

import java.io.IOException;
import java.net.Socket;

public class SecretaryFactory {
    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 2; i++) {
            Socket socket = new Socket("localhost", ServerApp.PORT);
            new Thread(new SecretaryRunnable(socket)).start();
        }
    }
}
