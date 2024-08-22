package com.example.sharedprefs;

import android.content.SharedPreferences;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.content.Intent;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

/**
 * HelloSharedPrefs is an adaptation of the HelloToast app from chapter 1.
 * It includes:
 * - Buttons for changing the background color.
 * - Maintenance of instance state.
 * - Themes and styles.
 * - Read and write shared preferences for the current count and the color.
 * <p>
 * This is the starter code for HelloSharedPrefs.
 */
public class MainActivity extends AppCompatActivity {
    // Current count
    private int mCount = 0;
    // Current background color
    private int mColor;
    // Text view to display both count and color
    private TextView mShowCountTextView;

    /**
     // Key for current count
     public static final String COUNT_KEY = "count";
     // Key for current color
     public static final String COLOR_KEY = "color";
     */

    private SharedPreferences mPreferences;
    private String sharedPrefFile =
            "com.example.android.sharedprefs";


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize views, color
        mShowCountTextView = findViewById(R.id.count_textview);
        mColor = ContextCompat.getColor(this,
                R.color.default_background);

        mPreferences = getSharedPreferences(sharedPrefFile, MODE_PRIVATE);


        /**
         // Restore preferences
         mCount = mPreferences.getInt(COUNT_KEY, 0);
         mShowCountTextView.setText(String.format("%s", mCount));
         mColor = mPreferences.getInt(COLOR_KEY, mColor);
         mShowCountTextView.setBackgroundColor(mColor); */

        // Set the background color of the TextView
        mShowCountTextView.setBackgroundColor(mColor);

        Button settingsButton = findViewById(R.id.settingsButton);
        settingsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Launch the SettingsActivity when the button is clicked
                Intent intent = new Intent(MainActivity.this, SettingsActivity.class);
                startActivity(intent);
            }
        });

    }

    /**
     * Handles the onClick for the background color buttons. Gets background
     * color of the button that was clicked, and sets the TextView background
     * to that color.
     *
     * @param view The view (Button) that was clicked.
     */
    public void changeBackground(View view) {
        int color = ((ColorDrawable) view.getBackground()).getColor();
        mShowCountTextView.setBackgroundColor(color);
        mColor = color;
    }

    /**
     * Handles the onClick for the Count button. Increments the value of the
     * mCount global and updates the TextView.
     *
     * @param view The view (Button) that was clicked.
     */
    public void countUp(View view) {
        mCount++;
        mShowCountTextView.setText(String.format("%s", mCount));
    }

    /**
     * Saves the instance state if the activity is restarted (for example,
     * on device rotation.) Here you save the values for the count and the
     * background color.
     *
     * @param outState The state data.
     */

    /**
     @Override
     protected void onSaveInstanceState(Bundle outState) {
     super.onSaveInstanceState(outState);

     outState.putInt(COUNT_KEY, mCount);
     outState.putInt(COLOR_KEY, mColor);
     }
     */


    /**
     @Override
     protected void onPause() {
     super.onPause();

     SharedPreferences.Editor preferencesEditor = mPreferences.edit();
     preferencesEditor.putInt(COUNT_KEY, mCount);
     preferencesEditor.putInt(COLOR_KEY, mColor);
     preferencesEditor.apply();
     } */

    @Override
    protected void onResume() {
        super.onResume();

        // Restore preferences
        mCount = mPreferences.getInt(AppConstants.COUNT_KEY, 0);
        mShowCountTextView.setText(String.format("%s", mCount));
        mColor = mPreferences.getInt(AppConstants.COLOR_KEY, ContextCompat.getColor(this, R.color.default_background));
        mShowCountTextView.setBackgroundColor(mColor);

    }


    /**
     * Handles the onClick for the Reset button. Resets the global count and
     * background variables to the defaults and resets the views to those
     * default values.
     *
     * @param view The view (Button) that was clicked.
     */
    public void reset(View view) {
        // Reset count
        mCount = 0;
        mShowCountTextView.setText(String.format("%s", mCount));

        // Reset color
        mColor = ContextCompat.getColor(this,
                R.color.default_background);
        mShowCountTextView.setBackgroundColor(mColor);

        // Clear preferences
        SharedPreferences.Editor preferencesEditor = mPreferences.edit();
        preferencesEditor.clear();
        preferencesEditor.apply();
    }
}
