package com.algofashion.etienne.algopaper;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnSnakeColors = findViewById(R.id.btn_snakecolors);
        btnSnakeColors.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent snakeIntent = new Intent(MainActivity.this, SnakeColorsActivity.class);
                startActivity(snakeIntent);
            }
        });

        Button btnPastelGradients = findViewById(R.id.btn_pastelgradients);
        btnPastelGradients.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent pastelIntent = new Intent(MainActivity.this, PastelGradientsActivity.class);
                startActivity(pastelIntent);
            }
        });

        Button btnSpiral = findViewById(R.id.btn_spiralcolor);
        btnSpiral.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent spiralIntent = new Intent(MainActivity.this, SpiralColorsActivity.class);
                startActivity(spiralIntent);
            }
        });

        Button btnSpiralfade = findViewById(R.id.btn_spiralcolorfade);
        btnSpiralfade.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent spiralfadeIntent = new Intent(MainActivity.this, SpiralColorsFadeActivity.class);
                startActivity(spiralfadeIntent);
            }
        });

        Button btnSpiralfadeMulti = findViewById(R.id.btn_spiralcolorfademulti);
        btnSpiralfadeMulti.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent spiralfademultiIntent = new Intent(MainActivity.this, SpiralColorsFadeMultiActivity.class);
                startActivity(spiralfademultiIntent);
            }
        });

        //System.out.println(hello());

    }

}
