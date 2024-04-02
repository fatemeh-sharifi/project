#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int NOT_FOUND_AMOUNT = -1;
const string DIVIDER = ", ";
const string ID_PRINT = "ID: ";
const string MODE_PRINT = "Mode: ";
const string USERNAME = "Username: ";
const string PLAYLISTS = "Playlists: ";
const string SONGS = "Songs: ";
const string FOLLOWINGS = "Followings: ";
const string FOLLOWERS = "Followers: ";
const string MUSIC_INFO_COLUMNS = "ID, Name, Artist, Year, Album, Tags, Duration";
const string PLAYLIST_INFO_COLUMNS = "Playlist_name, Songs_number, Duration";
const string FAVORITE_MUSIC_COLUMNS = "ID, Name, Artist";

const string POST_COMMAND = "POST";
const string GET_COMMAND = "GET";
const string PUT = "PUT";
const string DELETE = "DELETE";

const string BAD_REQUEST = "Bad Request";
const string PERMISSION_DENIED = "Permission Denied";
const string NOT_FOUND = "Not Found";
const string OK = "OK";
const string EMPTY = "Empty";

const string SIGNUP = "signup";
const string LOGIN = "login";
const string LOGOUT = "logout";
const string PLAYLIST = "playlist";
const string USERS = "users";
const string MUSIC = "music";
const string MUSICS = "musics";
const string REGISTERD_MUSIC = "registered_musics";
const string ADD_PLAYLIST = "add_playlist";
const string SEARCH_MUSIC = "search_music";
const string FOLLOW = "follow";
const string UNFOLLOW = "unfollow";
const string LIKE = "like";
const string RECOMMENDATIONS = "recommendations";
const string LIKES = "likes";

const string TITLE = "title";
const string PATH = "path";
const string YEAR = "year";
const string ALBUM = "album";
const string TAGS = "tags";
const string DURATION = "duration"; 
const string USER_INFO_COLUMNS = "ID, Mode, Username, Playlists_number/Songs_number";
const string ALL_MUSIC_INFO_COLUMNS = "ID, Name, Artist";
const string RECOMMENDED_MUSICS_COLUMNS = "ID, Name, Artist, Likes";
const string ONE_MUSIC_INFO_COLUMS = "ID, Name, Artist, Year, Album, Tags, Duration";
const string MODE = "mode";
const string USER_NAME = "username";
const string PASSWORD = "password";
const string ARTIST = "artist";
const string REGULAR_USER = "user";
const string NAME = "name";
const string ID = "id";
const string TAG = "tag";
const char TAG_DIVIDER = ';';
const int TYPE_INDEX = 0;
const int COMMAND_INDEX = 1;
const int NOT_INITIALIZED = -1;
const int MAX_RECOMMENDED_MUSIC = 5;

const int MAX_MINUTE_SECOND = 59;
const int SIXTY = 60;
const int TIME_DIVIDER_INDEX_ONE = 2;
const int TIME_DIVIDER_INDEX_TWO = 5;
const char TIME_DIVIDER = ':';
const string PRINT_DIVIDER = ", "; 
const char PRINT_TAGS_DIVIDER = ';';
const int TIME_STRING_SIZE = 8;

const int HOUR_FIRST_INDEX = 0;
const int MINUTE_FIRST_INDEX = 3;
const int SECOND_FIRST_INDEX = 6;