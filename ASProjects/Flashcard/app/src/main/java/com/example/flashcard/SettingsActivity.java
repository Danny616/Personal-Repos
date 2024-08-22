package com.example.flashcard;

import android.content.SharedPreferences;
import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.preference.PreferenceManager;

public class SettingsActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        // Load preferences
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(this);
        String savedQuestion = preferences.getString("question", "");
        String savedAnswer = preferences.getString("answer", "");
    }
}
