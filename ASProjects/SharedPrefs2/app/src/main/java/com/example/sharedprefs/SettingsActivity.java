package com.example.sharedprefs;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.ToggleButton;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

public class SettingsActivity extends AppCompatActivity {

    private SharedPreferences mPreferences;
    private String sharedPrefFile = "com.example.android.sharedprefs";

    private ToggleButton toggleCount;
    private EditText countValue;
    private ToggleButton toggleColor;
    private Spinner colorSpinner;
    private Button saveButton;
    private Button resetButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);

        mPreferences = getSharedPreferences(sharedPrefFile, MODE_PRIVATE);

        toggleCount = findViewById(R.id.toggleCount);
        countValue = findViewById(R.id.countValue);
        toggleColor = findViewById(R.id.toggleColor);
        colorSpinner = findViewById(R.id.colorSpinner);
        saveButton = findViewById(R.id.saveButton);
        resetButton = findViewById(R.id.resetButton);

        // Initialize the color spinner
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(
                this,
                R.array.colors,
                android.R.layout.simple_spinner_item
        );
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        colorSpinner.setAdapter(adapter);

        // Load and display preferences
        loadPreferences();

        // Handle Save button click
        saveButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                savePreferences();
            }
        });

        // Handle Reset button click
        resetButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                resetPreferences();
            }
        });
    }

    // Load and display preferences
    private void loadPreferences() {
        // code to load the preferences goes here

        if(toggleCount.isChecked()) {
            int count = mPreferences.getInt(AppConstants.COUNT_KEY, 0);
            countValue.setText(String.valueOf(count));
        } else {
            countValue.setText("");
        }

        if(toggleColor.isChecked()) {
            String color = mPreferences.getString(AppConstants.COLOR_KEY, "");
            colorSpinner.setSelection(getColorIdByName(color));
        } else {
            colorSpinner.setSelection(0);
        }
    }

    // Handle Save button click
    private void savePreferences() {
        // code to save the preferences goes here
        SharedPreferences.Editor preferencesEditor = mPreferences.edit();

        if (toggleCount.isChecked()) {
            int count = Integer.parseInt(countValue.getText().toString());
            preferencesEditor.putInt(AppConstants.COUNT_KEY, count);
        }

        if (toggleColor.isChecked()) {
            String colorName = colorSpinner.getSelectedItem().toString();
            int color = getColorIdByName(colorName);
            preferencesEditor.putInt(AppConstants.COLOR_KEY, color);
        }

        preferencesEditor.apply();
    }

    // Handle Reset button click
    private void resetPreferences() {
        // code to reset the preferences goes here
        SharedPreferences.Editor preferencesEditor = mPreferences.edit();

        preferencesEditor.clear();

        preferencesEditor.apply();
    }

    // Helper method to get color resource ID by name
    private int getColorIdByName(String colorName) {
        switch (colorName) {
            case "Red":
                return ContextCompat.getColor(this, R.color.red_background);
            case "Blue":
                return ContextCompat.getColor(this, R.color.blue_background);
            case "Green":
                return ContextCompat.getColor(this, R.color.green_background);
            case "Black":
                return ContextCompat.getColor(this, R.color.black_background);
            default:
                return ContextCompat.getColor(this, R.color.default_background);
        }
    }
}
