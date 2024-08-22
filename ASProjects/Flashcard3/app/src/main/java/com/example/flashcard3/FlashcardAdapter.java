package com.example.flashcard3;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class FlashcardAdapter extends RecyclerView.Adapter<FlashcardAdapter.FlashcardViewHolder> {

    private final List<String> questions;
    private final List<String> answers;
    private int expandedPosition = -1;

    public FlashcardAdapter(List<String> questions, List<String> answers) {
        this.questions = questions;
        this.answers = answers;
    }

    @NonNull
    @Override
    public FlashcardViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_flashcard, parent, false);
        return new FlashcardViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(@NonNull FlashcardViewHolder holder, int position) {
        String question = questions.get(position);
        String answer = answers.get(position);

        holder.questionTextView.setText(question);
        holder.answerTextView.setText(answer);

        final boolean isExpanded = position == expandedPosition;

        // Added a basic animation to the expansion and contraction of the answer
        if (isExpanded) {
            holder.answerTextView.setVisibility(View.VISIBLE);
            holder.answerTextView.animate().alpha(1.0f).setDuration(500).start();
        } else {
            holder.answerTextView.animate().alpha(0.0f).setDuration(500).withEndAction(() -> holder.answerTextView.setVisibility(View.INVISIBLE)).start();
        }

        holder.questionTextView.setOnClickListener(view -> {
            expandedPosition = isExpanded ? -1 : position;
            notifyDataSetChanged();
        });
    }


    @Override
    public int getItemCount() {
        return questions.size();
    }

    public static class FlashcardViewHolder extends RecyclerView.ViewHolder {
        TextView questionTextView;
        TextView answerTextView;

        public FlashcardViewHolder(@NonNull View itemView) {
            super(itemView);
            questionTextView = itemView.findViewById(R.id.questionTextView);
            answerTextView = itemView.findViewById(R.id.answerTextView);
        }
    }
}
