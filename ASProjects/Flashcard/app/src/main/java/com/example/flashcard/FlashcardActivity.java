package com.example.flashcard;

import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class FlashcardActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_flashcard);

        // Initialize the list of flashcards
        List<Flashcard> flashcards = new ArrayList<>();
        flashcards.add(new Flashcard("What is the capital of France?", "Paris"));
        flashcards.add(new Flashcard("How many continents are there?", "7"));
        flashcards.add(new Flashcard("What is the largest planet in our solar system?", "Jupiter"));

        // Initialize RecyclerView
        RecyclerView recyclerView = findViewById(R.id.flashcardRecyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        FlashcardAdapter adapter = new FlashcardAdapter(flashcards);
        recyclerView.setAdapter(adapter);
    }
}
