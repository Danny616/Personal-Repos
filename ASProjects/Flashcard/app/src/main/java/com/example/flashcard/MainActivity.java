package com.example.flashcard;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button startButton = findViewById(R.id.startButton);
        startButton.setOnClickListener(v -> {
            // Create an Intent to launch the FlashcardActivity
            Intent intent = new Intent(MainActivity.this, FlashcardActivity.class);
            startActivity(intent);
        });
    }
}