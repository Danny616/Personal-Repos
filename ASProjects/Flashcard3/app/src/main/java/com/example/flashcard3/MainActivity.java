package com.example.flashcard3;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private List<String> questions;
    private List<String> answers;

    RecyclerView showRecyclerView;

    private SharedPreferences mPreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        showRecyclerView = findViewById(R.id.flashcardRecyclerView);

        String sharedPrefFile = "com.example.android.sharedprefs";
        mPreferences = getSharedPreferences(sharedPrefFile, MODE_PRIVATE);

        showRecyclerView.setLayoutManager(new LinearLayoutManager(this));
        questions = new ArrayList<>();
        answers = new ArrayList<>();
        FlashcardAdapter adapter = new FlashcardAdapter(questions, answers);
        showRecyclerView.setAdapter(adapter);

        Button settingsButton = findViewById(R.id.SettingsButton);
        settingsButton.setOnClickListener(v -> {
            // Create an Intent to launch the SettingsActivity
            Intent intent = new Intent(MainActivity.this, SettingsActivity.class);
            startActivity(intent);
        });

        // Register a BroadcastReceiver to listen for preferences reset
        IntentFilter intentFilter = new IntentFilter("com.example.flashcard3.PREFERENCES_RESET");
        BroadcastReceiver resetReceiver = new BroadcastReceiver() {
            @Override
            public void onReceive(Context context, Intent intent) {
                // Handle the reset, for example, by clearing and updating the RecyclerView
                questions.clear();
                answers.clear();
                if (showRecyclerView.getAdapter() != null) {
                    showRecyclerView.getAdapter().notifyDataSetChanged();
                }
            }
        };
        registerReceiver(resetReceiver, intentFilter);
    }

    @Override
    protected void onResume() {
        super.onResume();

        // Initialize lists if not already done
        if (questions == null) {
            questions = new ArrayList<>();
        }
        if (answers == null) {
            answers = new ArrayList<>();
        }

        // Retrieve updated data from SharedPreferences
        String updatedQuestion = mPreferences.getString(Flashcard.question, "");
        String updatedAnswer = mPreferences.getString(Flashcard.answer, "");

        // Add updated data to the lists
        questions.add(updatedQuestion);
        answers.add(updatedAnswer);

        // Notify the adapter that the data has changed
        if (showRecyclerView.getAdapter() != null) {
            showRecyclerView.getAdapter().notifyDataSetChanged();
        }
    }

}
