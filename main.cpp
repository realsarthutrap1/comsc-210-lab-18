// COMSC-210 | Lab 18 | Sarthak Pani
#include <iostream>
#include <iomanip>
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
    void printReviews() const;
};

int main() {
    Movie movie("Lord of the Rings");
    movie.addReview(3.3, "An epic journey with stunning visuals.");
    movie.addReview(2.3, "Too long, but the battles are incredible.");
    movie.addReview(2.0, "The best fantasy film ever made.");
    movie.printReviews();
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

// print reviews from newest to oldest and calculate their average
void Movie::printReviews() const {
    cout << "Movie: " << title << endl;
    cout << fixed << setprecision(1);

    const Review* current = head;
    double total = 0.0;
    int count = 0;
    while (current != nullptr) {
        count++;
        cout << "  Review #" << count << ": " << current->rating
             << ": " << current->comment << endl;
        total += current->rating;
        current = current->next;
    }

    if (count == 0) {
        cout << "  No reviews yet." << endl;
    }
    double average = count > 0 ? total / count : 0.0;
    cout << "  Average rating: " << average << endl;
}
