This console program aims to act as a helpful assistant for managing and storing
data relevant to an offline "season" in Super Smash Bros. Ultimate. This mode
was originally created by myself as a fun way to practice against the computer
while also having an actual goal in mind. While this tool is less "necessary"
due to the inclusion of a single player mode via spirits, an offline season is
still nice for casual play without the mandate of spirits, which although
enjoyable, differs greatly from regular gameplay.

This is just the beginning of the project, so the first milestone is to have a
single working season, while also supporting lifetime careers for individual
characters/actual players in the future, as well as more comprehensive stat
tracking and options for a user to adjust the season to their own preferences.


Future Feature List:

Stage 1. A set season (no settings or tuning available) that allows a player
         to play through a season with computer teams also created and set.
         One of the key features in the release is that computer teams will
         simulate their battles through the use of an algorithm, instead of
         just randomly. One of the major aims in this is to create a league
         where opponents feel like competitors rather than just luck-of-the-draw
         challengers in every single match.

         A single season should generate the 19 other teams (there is nothing
         special about this number I just feel that 20 teams should give a good
         impression for initial use), set up the 190 matches, tell
         the user who their opponent is, allow data entry for the match, simulate
         computer battles for the week(1 match a week), and keep track of
         rankings, which will be used for creating the playoff bracket in
         the future.

Stage 2. To be determined.

Other features to be added
-tracking a Human players 1v1 2v2 3v3 4v4 matches separately: can be done by looking
    at the numberOfPlayers on each team. A team with 2 players will always feature 2v2
    battles, so add to total, then to the corresponding 1,2,3,4 player match holders
    when displaying stats
-track stage kills and deaths
-keep track of win/lose streak; will be used to adjust simulation of cpu Teams
-ability for cpu teams to actually improve or get worse over time/ playoff teams get boost??
-different season options/ playoff setups
-a Hplayer keeps life stats, the team keeps season based stats, add kill and death
 tracking for teams to compare over the season, instead of only tracking all time
 kill/death data (which also allows differential tracking for tie breakers)
-records: win streaks, losing streaks, all time wins user/fighter/character,
 all time losses, top x,y,z (10, 5,1 i.e.) finishes in a season 1 = champions, all time kos,
 all time deaths, season kills, season deaths, stage records et cetera.
 -multi human team seasons
 tbI = to be implemented
-simulation improvements, use record, streaks(tbI), and player tier list(tbI) in calculation
-currently, only stock based seasons are supported, but other types can be implemented;
the only difficulty is setting up the simulation of the matches
-although not mandatory, data entry for matches should have safe guards for invalid
data entries, such as kills and deaths matching, kills in a match not exceeding the amount of lives,
no negative values etc. ---> do with functions that ask for specific values and dont return until they get a valid one
-> this also applies to creating a character 
