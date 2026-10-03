// COMSC-210 | Lab 18 | Sarthak Pani
#include <string>
using namespace std;

class Movie {
private:
    struct Review {
        double rating;
        string comment;
        Review* next;
    };

    string title;
    Review* head;

public:
    Movie(const string& movieTitle);
    ~Movie();
    // copying is disabled until deep copying is implemented
    Movie(const Movie& other) = delete;
    Movie& operator=(const Movie& other) = delete;
    void addReview(double rating, const string& comment);
};

int main() {
    Movie movie("Lord of the Rings");
    movie.addReview(3.3, "An epic journey with stunning visuals.");
    movie.addReview(2.3, "Too long, but the battles are incredible.");
    movie.addReview(2.0, "The best fantasy film ever made.");
    return 0;
}

Movie::Movie(const string& movieTitle) {
    title = movieTitle;
    head = nullptr;
}

// release every review owned by this movie
Movie::~Movie() {
    while (head != nullptr) {
        Review* oldHead = head;
        head = head->next;
        delete oldHead;
    }
}

// insert the newest review at the head of the list
void Movie::addReview(double rating, const string& comment) {
    head = new Review{rating, comment, head};
}
