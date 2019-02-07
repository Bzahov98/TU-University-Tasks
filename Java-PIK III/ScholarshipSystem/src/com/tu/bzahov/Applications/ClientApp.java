package com.tu.bzahov.Applications;

import com.tu.bzahov.Server.ServerApp;

import java.io.Closeable;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;
@Deprecated
public class ClientApp {


    public static final int MAX_OPERATIONS = 2;

    public static void main(String args[]) throws IOException {
        int operation;
        Socket s = new Socket("localhost", ServerApp.PORT);
        Scanner scan = new Scanner(System.in);
        Scanner scan2 = new Scanner(s.getInputStream());
        PrintStream printout = new PrintStream(s.getOutputStream());
        System.out.println("Please Choose option: ");

            do {
                System.out.println("0.For Exit");
                System.out.println("1.Кандидатствай за стипендия за успех");
                System.out.println("2.Кандидатствай за специална стипендия");
                try {
                    operation = scan.nextInt();
                }catch (InputMismatchException e){
                    operation = -1;
                    continue;
                }printout.println(operation);

                String input = scan2.nextLine();
                System.out.println(input);
            }while (shouldExit(operation));


        closeResources(s, scan, scan2);

    }

    private static <T extends Closeable> void closeResources(T ... closable ){
        Arrays.stream(closable).forEach(close-> {
            try {
                if (close!= null) {
                    close.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        });
        /*if (s != null)
            s.close();
        if (scan != null)
            scan.close();
        if (scan2 != null)
            scan2.close();
            */
    }

    private static boolean shouldExit(int operation) {
        return (operation == 0 || isInvalid(operation));
    }

    private static boolean isInvalid(int operation) {
        return operation < 0 || operation > MAX_OPERATIONS;
    }
}
