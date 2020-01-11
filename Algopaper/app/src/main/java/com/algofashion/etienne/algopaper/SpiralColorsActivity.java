package com.algofashion.etienne.algopaper;

import android.graphics.Bitmap;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.SeekBar;

import org.json.JSONException;
import org.json.JSONObject;

public class SpiralColorsActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public static native void SpiralColors(int[] pixels, int w, int h, String jparam);
    Bitmap RenderedImage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_spiralcolors);

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
        ImageView view = findViewById(R.id.iv_SpiralColors);
        view.setImageBitmap(RenderedImage);
    }


    void generateImage() {
        Bitmap bitmap = Bitmap.createBitmap(800, 800, Bitmap.Config.ARGB_8888);
        int w = bitmap.getWidth();
        int h = bitmap.getHeight();
        int[] pixels = new int[w * h];
        System.out.println("Running SpiralColors CPP");
        String jparam = assembleParams();
        SpiralColors(pixels, w, h, jparam);
        System.out.println("Done running SpiralColors");
        bitmap.setPixels(pixels, 0 , w , 0 , 0, w, h);
        RenderedImage = bitmap;
    }

    String assembleParams() {
        // TODO find good param values
        SeekBar slider_am = findViewById(R.id.slider_anglemodulo);
        double am = slider_am.getProgress() / 1000.0f * 2 * Math.PI; // 0 - 2 * PI

        SeekBar slider_rm = findViewById(R.id.slider_radiusmodulo);
        double rm  = 100.0f + slider_rm.getProgress() / 1000.0f * 900.0f; // 100 - 1000

        SeekBar slider_rp = findViewById(R.id.slider_radiusperiod);
        double radiusperiod  = 100.0f + slider_rp.getProgress() / 1000.0f * 900.0f; // 100 - 1000

        JSONObject json = new JSONObject();
        try {
            json.put("angleModulo", am);
            json.put("radiusModulo", rm);
            json.put("radiusPeriod", radiusperiod);
        } catch (JSONException e) {

        }

        return json.toString();
    }
}
