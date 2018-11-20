package com.tu.bzahov;

import com.tu.bzahov.interfaces.ICompetition;
import com.tu.bzahov.competitions.FootballCompetition;
import com.tu.bzahov.competitions.Formula1Competition;
import com.tu.bzahov.competitions.HorseCompetition;
import com.tu.bzahov.exceptions.EmptySetException;
import com.tu.bzahov.exceptions.MyEventException;

public class CreateEvent {
    protected String typeOfEvent;

    private final static String footballCompetition = "FootballCompetition";
    private final static String horseCompetition    = "HorseCompetition";
    private final static String formula1Competition = "Formula1Competition";

    public ICompetition getEvent(String competitionType) throws MyEventException {
        switch (competitionType) {

            case (footballCompetition):
                return new FootballCompetition();
            case (horseCompetition):
                return new HorseCompetition();
            case (formula1Competition):
                return new Formula1Competition();

            default:
                throw  new MyEventException() ;
        }
    }

    public static void fillSchedule(ICompetition competition, Participant[] partArr)
            throws EmptySetException {

        if (partArr.length == 0){
            throw new EmptySetException();
        }

        int arrLength = partArr.length;
        Participant[] newArr = new Participant[arrLength];
        System.arraycopy(partArr, 0, newArr,0, arrLength);
        competition.setSchedule(newArr);
    }




}
