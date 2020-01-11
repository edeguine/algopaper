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

public class SpiralColorsFadeMultiActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public static native void SpiralColorsFadeMulti(int[] pixels, int w, int h, String jparam);
    Bitmap RenderedImage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_spiralcolorsfademulti);

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
        ImageView view = findViewById(R.id.iv_SpiralColorsFadeMulti);
        view.setImageBitmap(RenderedImage);
    }


    void generateImage() {
        Bitmap bitmap = Bitmap.createBitmap(800, 800, Bitmap.Config.ARGB_8888);
        int w = bitmap.getWidth();
        int h = bitmap.getHeight();
        int[] pixels = new int[w * h];
        System.out.println("Running SpiralColorsFadeMulti CPP");
        String jparam = assembleParams();
        SpiralColorsFadeMulti(pixels, w, h, jparam);
        System.out.println("Done running SpiralColorsFadeMulti");
        bitmap.setPixels(pixels, 0 , w , 0 , 0, w, h);
        RenderedImage = bitmap;
    }

    String assembleParams() {
        // TODO find good param values
        SeekBar slider_br = findViewById(R.id.slider_baseradius);
        double baseradius = 100.0f + slider_br.getProgress() / 1000.0f * 900.0f; // 100 - 1000

        SeekBar slider_fm = findViewById(R.id.slider_fademultiplier);
        double fm  = 1.0f + slider_fm.getProgress() / 1000.0f * 999.0f; // 200 - 1000

        SeekBar slider_cc = findViewById(R.id.slider_countcenters);
        int cc  = (int)(1.0f + slider_fm.getProgress() / 1000.0f * 49.0f); // 1 - 50

        JSONObject json = new JSONObject();
        try {
            json.put("BaseRadius", baseradius);
            json.put("FadeMultiplier", fm);
            json.put("CountCenters", cc);
        } catch (JSONException e) {

        }

        return json.toString();
    }
}
