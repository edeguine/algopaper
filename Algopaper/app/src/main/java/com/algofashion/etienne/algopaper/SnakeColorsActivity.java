package com.algofashion.etienne.algopaper;

import android.graphics.Bitmap;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.SeekBar;

import org.json.JSONException;
import org.json.JSONObject;

public class SnakeColorsActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public static native void SnakeColors(int[] pixels, int w, int h, String jparam);
    Bitmap RenderedImage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_snakecolors);

        // Wire up buttons

        Button btn_generate = findViewById(R.id.btn_generate);
        btn_generate.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                updateImage();
            }
        });
    }

    void updateImage() {
        generateImage();
        ImageView view = findViewById(R.id.iv_SnakeColors);
        view.setImageBitmap(RenderedImage);
    }


    void generateImage() {
        Bitmap bitmap = Bitmap.createBitmap(800, 800, Bitmap.Config.ARGB_8888);
        int w = bitmap.getWidth();
        int h = bitmap.getHeight();
        int[] pixels = new int[w * h];
        System.out.println("Running SnakeColors CPP");
        String jparam = assembleParams();
        SnakeColors(pixels, w, h, jparam);
        System.out.println("Done running SnakeColors");
        bitmap.setPixels(pixels, 0 , w , 0 , 0, w, h);
        RenderedImage = bitmap;
    }

    String assembleParams() {
        SeekBar sliderX = findViewById(R.id.slider_xperiod);
        double xperiod = sliderX.getProgress() / 1000.0f * 200; // 0 - 200

        SeekBar sliderY = findViewById(R.id.slider_yperiod);
        double yperiod = sliderY.getProgress() / 1000.0f * 200; // 0 - 200

        SeekBar sliderZ = findViewById(R.id.slider_zperiod);
        double zperiod = sliderZ.getProgress() / 1000.0f * 200; // 0 - 200

        JSONObject json = new JSONObject();
        try {
            json.put("xperiod", xperiod);
            json.put("yperiod", yperiod);
            json.put("zperiod", zperiod);
        } catch (JSONException e) {

        }

        return json.toString();
    }
}
