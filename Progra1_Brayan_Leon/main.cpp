
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <sstream>
/*
color
director_name
num_critic_for_reviews
duration
director_facebook_likes
actor_3_facebook_likes
actor_2_name
actor_1_facebook_likes
gross
genres
actor_1_name
movie_title
num_voted_users
cast_total_facebook_likes
actor_3_name
facenumber_in_poster
plot_keywords
movie_imdb_link
num_user_for_reviews
language
country
content_rating
budget
title_year
actor_2_facebook_likes
imdb_score
aspect_ratio
movie_facebook_likes
*/


using namespace std;
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();


}
