package com.example.flashcard3;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class SettingsActivity extends AppCompatActivity {

    private SharedPreferences mPreferences;

    private EditText questionIn;
    private EditText answerIn;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        String sharedPrefFile = "com.example.android.sharedprefs";
        mPreferences = getSharedPreferences(sharedPrefFile, MODE_PRIVATE);

        Button saveButton = findViewById(R.id.save_button);
        Button resetButton = findViewById(R.id.reset_button);
        questionIn = findViewById(R.id.questionTextView);
        answerIn = findViewById(R.id.answerTextView);

        // Load and display preferences
        loadPreferences();

        // Handle Save button click
        saveButton.setOnClickListener(v -> savePreferences());

        // Handle Reset button click
        resetButton.setOnClickListener(v -> resetPreferences());
    }

    private void loadPreferences() {
        String questionText = mPreferences.getString(Flashcard.question, "");
        questionIn.setText(questionText);

        String answerText = mPreferences.getString(Flashcard.answer, "");
        answerIn.setText(answerText);
    }


    private void savePreferences() {
        String questionText = questionIn.getText().toString();
        String answerText = answerIn.getText().toString();

        if (questionText.isEmpty() || answerText.isEmpty()) {
            // Show a Toast message indicating that both fields need to be filled
            Toast.makeText(this, "Both question and answer fields must be filled", Toast.LENGTH_SHORT).show();
        } else {
            // Save preferences
            SharedPreferences.Editor preferencesEditor = mPreferences.edit();
            preferencesEditor.putString(Flashcard.question, questionText);
            preferencesEditor.putString(Flashcard.answer, answerText);
            preferencesEditor.apply();
            finish();
        }
    }


    private void resetPreferences() {
        // Reset preferences
        SharedPreferences.Editor preferencesEditor = mPreferences.edit();
        preferencesEditor.clear();
        preferencesEditor.apply();

        // Broadcast intent to notify other components (e.g., MainActivity) about the reset
        Intent intent = new Intent("com.example.flashcard3.PREFERENCES_RESET");
        sendBroadcast(intent);

        finish();
    }

}