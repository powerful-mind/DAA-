// Name:- Avishkar Jijabhau Jadhav
// PRN:- 123B1F032
// 21/7/2025

#include <bits/stdc++.h> 
using namespace std; 
class Movie{ 
public: 
    string title; 
    float rating; 
    int release_year; 
    int popularity; 
 
    // Constructor 
    Movie(string t, float r, int y, int p) { 
        title = t; 
        rating = r; 
        release_year = y; 
        popularity = p; 
    } 
 
    void display() const{ 
        cout << title << " | Rating: " << rating 
             << " | Year: " << release_year 
             << " | Popularity: " << popularity << endl; 
    } 
 
}; 
 
class Moviesorter{ 
private: 
    vector <Movie> movies; 
    int partition(int low, int high, bool (*compare)(const Movie &,const Movie &)){ 
        Movie pivot = movies[low]; 
        int i = low; 
        int j = high; 
        while(i<j){ 
            while (compare(movies[i], pivot) && i <= high - 1) { 
                i++; 
            } 
            while (!compare(movies[j], pivot) && j >= low + 1) { 
                j--; 
            } 
            if (i < j) swap(movies[i], movies[j]); 
        } 
        swap(movies[low], movies[j]); 
        return j; 
    } 
 
    void quicksort(int low, int high ,bool (*compare)(const Movie &,const Movie &)){ 
        if(low < high){ 
            int pIndex = partition(low,high,compare); 
            quicksort(low,pIndex-1,compare); 
            quicksort(pIndex+1, high, compare); 
 
        } 
    } 
public: 
    void addmovie(int n){ 
        for (int i = 0; i < n; i++) { 
            string title; 
            float rating; 
            int year, pop; 
 
            cout << "\nEnter details for Movie " << i + 1 << ":\n"; 
            cin.ignore(); 
            cout << "Title: "; 
            getline(cin, title); 
            cout << "Rating: "; 
            cin >> rating; 
            cout << "Release Year: "; 
            cin >> year; 
            cout << "Popularity: "; 
            cin >> pop; 
 
            movies.emplace_back(title, rating, year, pop); 
        } 
    } 
 
    void sortmovies(string sort_by){ 
        bool (*compare)(const Movie &,const Movie &); 
        if (sort_by == "rating") 
            compare = compareByRating; 
        else if (sort_by == "year") 
            compare = compareByYear; 
        else if (sort_by == "popularity") 
            compare = compareByPopularity; 
        else { 
            cout << "Invalid choice. Defaulting to rating.\n"; 
            compare = compareByRating; 
        } 
 
        quicksort(0,movies.size()-1,compare); 
 
        for(const auto &m: movies){ 
            m.display(); 
        } 
    } 
 
        static bool compareByRating(const Movie &a, const Movie &b) { 
            return a.rating < b.rating; 
        } 
        static bool compareByYear(const Movie &a, const Movie &b) { 
            return a.release_year < b.release_year; 
        } 
        static bool compareByPopularity(const Movie &a, const Movie &b) { 
           return a.popularity < b.popularity; 
        } 
}; 
 
int main(){ 
    int n; 
    cout << "Enter the number of movies you want to sort:"; 
    cin>> n; 
Moviesorter sorter; 
sorter.addmovie(n); 
cout << "\nSort movies by (rating/year/popularity): "; 
string sort_by; 
cin >> sort_by; 
sorter.sortmovies(sort_by); 
return 0; 
}