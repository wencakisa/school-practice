#include <stdio.h>

#define MAX_VIDEOS 100
#define TOP_VIDEOS_LIMIT 10
#define VIDEOS_TO_UPLOAD 5

static char *VIDEO_TITLES[VIDEOS_TO_UPLOAD] = {
    "Григовор / Гена - Авантаж",
    "Eminem - Space Bound",
    "Жлъч / Гена - И утре е ден (ONE SHOT)",
    "J Cole - Love Yourz",
    "Kendrick Lamar - The Blacker The Berry"
};

typedef struct user_t user_t;

typedef struct video_t {
    int likes;
    int dislikes;
    char *title;
    user_t *uploader;
} video_t;

typedef struct user_t {
    char *username;
    char *password;
    video_t videos[MAX_VIDEOS];
} user_t;

void upload_videos(video_t*, user_t*, user_t*);
user_t *least_liked(video_t*);
int get_total_likes(user_t*);
int get_average_likes(user_t*) ;
user_t *most_liked_uploader(video_t*);

int main() {
    video_t videos[TOP_VIDEOS_LIMIT];

    user_t first_user;
    first_user.username = "wencakisa";
    first_user.password = "nababatihvurchiloto";

    user_t second_user;
    second_user.username = "sisko";
    second_user.password = "spaceboundrocketship";

    upload_videos(videos, &first_user, &second_user);

    printf("User with least liked videos: %s\n", least_liked(videos)->username);
    printf("Most liked uploader: %s\n", most_liked_uploader(videos)->username);

    return 0;
}

void upload_videos(video_t *videos, user_t *u1, user_t *u2) {
    for (size_t i = 0, x = 0, y = 0; i < VIDEOS_TO_UPLOAD; i++) {
        video_t video;

        video.likes = (i % 2) ? (5000 - (50 * i)) : (3000 - (30 * i));
        video.dislikes = (i % 2) ? (10 - i) : (20 - i);
        video.title = VIDEO_TITLES[i];
        video.uploader = (i % 2) ? u1 : u2;
        video.uploader->videos[(i % 2) ? x++ : y++] = video;

        videos[i] = video;
    }
}

user_t *least_liked(video_t *videos) { 
    video_t min_likes_video = videos[0];

    for (size_t i = 1; i < VIDEOS_TO_UPLOAD; i++) {
        video_t current_video = videos[i];

        if(current_video.likes < min_likes_video.likes) {
            min_likes_video = current_video;
        }
    }

    return min_likes_video.uploader;
}

int get_total_likes(user_t *uploader) {
    int total_likes = 0;

    video_t *uploader_videos = uploader->videos;
    size_t len = sizeof(*uploader_videos) / sizeof(uploader_videos[0]);

    for (size_t i = 0; i < len; i++) {
        total_likes += uploader_videos[i].likes;
    }

    return total_likes;
}

int get_average_likes(user_t *uploader) {
    return get_total_likes(uploader) / VIDEOS_TO_UPLOAD;
}

user_t *most_liked_uploader(video_t *videos) {
    user_t *most_liked_uploader = videos[0].uploader;
    int most_liked_uploader_avg = get_average_likes(most_liked_uploader);

    for (size_t i = 1; i < VIDEOS_TO_UPLOAD; i++) {
        user_t *current_uploader = videos[i].uploader;
        int current_uploader_avg = get_average_likes(current_uploader);

        if(current_uploader_avg > most_liked_uploader_avg) {
            most_liked_uploader = current_uploader;
        }
    }

    return most_liked_uploader;
}

