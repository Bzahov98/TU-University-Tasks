package com.tu.bzahov;

import com.tu.bzahov.competitions.FootballCompetition;
import com.tu.bzahov.exceptions.EmptySetException;
import com.tu.bzahov.exceptions.MyEventException;
import com.tu.bzahov.interfaces.ICompetition;

public class App {

    private static final double MINIMUM_CHANCE_FOR_WIN = 1.1d;

    public static void main(String[] args) {
        // TODO: Add main function
        Participant part1 = new Participant(0,22,"Pesho");
        Participant part2 = new Participant(1,22,"Gosho");
        Participant part3 = new Participant(2,22,"Ivan");

        Participant[] partArr = new Participant[3];
        partArr[0]= part1;
        partArr[1]= part2;
        partArr[2]= part3;
        CreateEvent createEvent = new CreateEvent();

        try {
            FootballCompetition footballCompetition =(FootballCompetition) createEvent.getEvent("FootballCompetition");
            CreateEvent.fillSchedule(footballCompetition, partArr);
            System.out.println("Test for write data: array length: " + footballCompetition.getSchedule().length);
            System.out.println();

            bets(footballCompetition,1,2);
            bets(footballCompetition,1,8);
            bets(footballCompetition,1,118);

        } catch (MyEventException e) {
            System.out.println(e.getMessage());
        } catch (EmptySetException e) {
            e.printStackTrace();
        }
    }

    public static void bets(ICompetition competition, int id, double bet) throws NullPointerException{
        if (competition == null) throw new NullPointerException();
        Participant[] schedule = competition.getSchedule();
        Participant currentParticipant = schedule[id];

        double oldBet = currentParticipant.getBetForWin();
        double curChance = currentParticipant.getChanceForWin();

        double newBet = calculateNewBetForWin(oldBet,bet);
        currentParticipant.setBetForWin(newBet);
        System.out.println("Bet for Win: old|new |" + oldBet+ "|"+ newBet+"|");

        double newChance = calculateNewChanceForWin(curChance,oldBet,newBet);
        currentParticipant.setChanceForWin(newChance);
        System.out.println("Chance  Win: old|new |" + curChance+ "|"+ newChance + "|");
        System.out.println();
    }

    private static double calculateNewBetForWin(double oldBet, double bet) {
        if (oldBet == 0){
            return bet;
        }
        return (oldBet + bet) / oldBet;
    }

    private static double calculateNewChanceForWin(double oldChance, double oldBet, double newBet) {
        double percentageComponent;
        if (oldBet == 0){
            percentageComponent = 0.0;
        }else percentageComponent = ((newBet - oldBet) / oldBet);

        double newChance = oldChance - percentageComponent;
        //value less than 0 if d1 is numerically less than d2
        int compare = Double.compare(newChance, App.MINIMUM_CHANCE_FOR_WIN);
        System.err.println(newBet+"|"+ App.MINIMUM_CHANCE_FOR_WIN +"| "+ compare);
        if (compare < 0){
            newChance = 1.1;
        }
        return newChance;
    }

}
