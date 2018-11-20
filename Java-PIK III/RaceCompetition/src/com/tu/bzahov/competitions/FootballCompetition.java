package com.tu.bzahov.competitions;

import com.tu.bzahov.interfaces.ICompetition;
import com.tu.bzahov.Participant;

public class FootballCompetition implements ICompetition {

    private String fastestGoal;
    private static Participant[] schedule = null;

    public FootballCompetition() {}

    public FootballCompetition(String fastestGoal) {
        this.fastestGoal = fastestGoal;
    }

    @Override
    public Participant[] getSchedule() {
        return schedule;
    }

    @Override
    public void setSchedule(Participant[] schedule) {
        FootballCompetition.schedule = schedule;
    }

    public String getFastestGoal() {
        return fastestGoal;
    }

    public void setFastestGoal(String fastestGoal) {
        this.fastestGoal = fastestGoal;
    }
}
