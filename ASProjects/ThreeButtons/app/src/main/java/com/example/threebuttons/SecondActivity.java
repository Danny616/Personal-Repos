package com.example.threebuttons;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        TextView textView = findViewById(R.id.textView);

        // Retrieve the selected text passage from the Intent
        Intent intent = getIntent();
        String textToDisplay = intent.getStringExtra("textToDisplay");

        // Display the selected text passage in the TextView
        textView.setText(textToDisplay);
    }
}