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

public class PastelGradientsActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public static native void PastelGradients(int[] pixels, int w, int h, String jparam);
    Bitmap RenderedImage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pastelgradients);

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
        ImageView view = findViewById(R.id.iv_PastelGradients);
        view.setImageBitmap(RenderedImage);
    }


    void generateImage() {
        Bitmap bitmap = Bitmap.createBitmap(800, 800, Bitmap.Config.ARGB_8888);
        int w = bitmap.getWidth();
        int h = bitmap.getHeight();
        int[] pixels = new int[w * h];
        System.out.println("Running PastelGradients CPP");
        String jparam = assembleParams();
        PastelGradients(pixels, w, h, jparam);
        System.out.println("Done running PastelGradients");
        bitmap.setPixels(pixels, 0 , w , 0 , 0, w, h);
        RenderedImage = bitmap;
    }

    String assembleParams() {
        // TODO find good param values
        SeekBar slider_ph = findViewById(R.id.slider_ph);
        int ph = (int) (1 + slider_ph.getProgress() / 1000.0f * 99); // 1 - 100

        SeekBar slider_yo = findViewById(R.id.slider_yoffset);
        int yoffset = (int) (1 + slider_yo.getProgress() / 1000.0f * 99); // 1 - 100

        SeekBar slider_mp = findViewById(R.id.slider_mixperiod);
        double mixperiod = 100 +  slider_mp.getProgress() / 1000.0f * 900; // 100 - 1000

        JSONObject json = new JSONObject();
        try {
            json.put("ph", ph);
            json.put("yoffset", yoffset);
            json.put("mixperiod", mixperiod);
        } catch (JSONException e) {

        }

        return json.toString();
    }
}
