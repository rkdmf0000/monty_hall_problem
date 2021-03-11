#include <iostream>
#include <cstdio>
#include <random>

int main() {

    long long lose_cnt(0);
    long long win_cnt(0);

    long long lose_c_cnt(0);
    long long win_c_cnt(0);

    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::uniform_int_distribution<int> rd_dist_correct(0,2);


    long long buffer_totals(0);
    double win_avgs(0);
    double win_c_avgs(0);

    while(true) {

        /**
         * rand
         * */
        int the_correct = rd_dist_correct(mersenne); //correct number
        int challenger = rd_dist_correct(mersenne); // challenger's answer
        int mod_quest = rd_dist_correct(mersenne); // moderator's pick

        /**
         * choice not correct answer
         * */
        while(the_correct == mod_quest || challenger == mod_quest) {
            mod_quest = rd_dist_correct(mersenne);
        };

        /**
         * when you do not change answer
         * */
        if (the_correct == challenger) ++win_cnt;
        else ++lose_cnt;

        /**
         * or when you changed a answer
         */
        int challenger_nd = rd_dist_correct(mersenne); // new challenger's answer
        while(challenger_nd == challenger || challenger_nd == mod_quest) {
            challenger_nd = rd_dist_correct(mersenne);
        };

        if (the_correct == challenger_nd) ++win_c_cnt;
        else ++lose_c_cnt;

        buffer_totals = win_cnt+lose_cnt;
        win_avgs = win_cnt / (double)buffer_totals * 100;
        win_c_avgs = win_c_cnt / (double)buffer_totals * 100;
        printf("*TOTAL TRIES : %d / ", buffer_totals);
        printf("NORMAL WIN : %d / ", win_cnt);
        printf("NORMAL LOSE : %d / ", lose_cnt);
        printf("*NORMAL AVG : %04f / ", win_avgs);
        printf("CHANGED WIN : %d / ", win_c_cnt);
        printf("CHANGED LOSE : %d / ", lose_c_cnt);
        printf("*CHANGED AVG : %04f\n ", win_c_avgs);

        if (win_cnt+lose_cnt >= 50000)
            break;
    };

    return 0;
};