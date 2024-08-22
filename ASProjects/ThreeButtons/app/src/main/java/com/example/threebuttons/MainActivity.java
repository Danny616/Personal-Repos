package com.example.threebuttons;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button buttonTextOne = findViewById(R.id.buttonTextOne);
        Button buttonTextTwo = findViewById(R.id.buttonTextTwo);
        Button buttonTextThree = findViewById(R.id.buttonTextThree);

        buttonTextOne.setOnClickListener(v -> launchSecondActivity("Text Passage One"));

        buttonTextTwo.setOnClickListener(v -> launchSecondActivity("Text Passage Two"));

        buttonTextThree.setOnClickListener(v -> launchSecondActivity("Text Passage Three"));
    }

    private void launchSecondActivity(String textToDisplay) {
        Intent intent = new Intent(this, SecondActivity.class);
        intent.putExtra("textToDisplay", textToDisplay);
        startActivity(intent);
    }
}