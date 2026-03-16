1. Membuat Titik
   <img width="642" height="510" alt="titik" src="https://github.com/user-attachments/assets/3bf29bb6-fd15-4b76-ac79-a248801ae319" />

2. Membuat Garis
   <img width="643" height="511" alt="garis" src="https://github.com/user-attachments/assets/61651b53-2ad4-43df-a420-c30de2c0c893" />

3. Membuat Segitiga
   <img width="642" height="509" alt="segitiga" src="https://github.com/user-attachments/assets/00d1f967-a986-4377-ba39-4fa7e0bd6bc6" />

4. Membuat Segiempat Penuh
   <img width="641" height="511" alt="segiempat" src="https://github.com/user-attachments/assets/4db768df-2400-408e-abc5-98f4f69c759f" />

TUGAS
1. GL_LINE_STRIP dan GL_LINE_LOOP

   perbedaanya, GL_LINE_STRIP menghubungkan setiap titik secara berurutan dan        tidak menutup kembali ke titik pertamanya. Jadi garis berhenti di titik           terakhir. Sedangkan GL_LINE_LOOP menghubungkan titik secara berurutan tetapi      titik terakhir dihubungkan kembali ke titik pertama seperti membentuk loop.
   
   a. GL_LINE_STRIP
   
      kode 
   
   <img width="346" height="491" alt="line_strip code" src="https://github.com/user-attachments/assets/61d0f39d-2117-4db8-88ff-d59991908a12" />
      
      hasil = <img width="639" height="496" alt="line_strip" src="https://github.com/user-attachments/assets/3e26e812-4ec2-4377-8e15-0efea876c3dc" />

   b. GL_LINE_LOOP
   
      kode

    <img width="347" height="450" alt="line_loop code" src="https://github.com/user-attachments/assets/c677a136-0cd6-48ce-8a30-24f51f93d82c" />
      
      hasil = <img width="600" height="432" alt="line_loop" src="https://github.com/user-attachments/assets/542eef62-ad49-434f-8d99-47503a6c9fab" />

2. GL_TRIANGLE_FAN dan GL_TRIANGLE_STRIP

   GL_TRIANGLES untuk membuat segitiga-segitiga yang berdiri sendiri (tidak saling terhubung). Setiap tiga vertex akan membentuk satu segitiga. Kalau GL_TRIANGLE_FAN digunakan untuk membuat segitiga yang menyebar dari satu titik pusat. Vertex pertama menjadi titik pusat, lalu semua vertex berikutnya terhubung dengan titik tersebut. Setelah dua vertex pertama, setiap vertex tambahan akan membentuk segitiga baru yang berbagi titik pusat yang sama.Sedangkan GL_TRIANGLE_STRIP untuk membuat rangkaian segitiga yang saling terhubung. Setelah dua vertex pertama, setiap vertex baru yang ditambahkan akan membentuk satu segitiga baru bersama dua vertex sebelumnya sehingga membentuk pola zig zag

   a. GL_TRIANGLE_FAN

   kode
   
   <img width="300" height="483" alt="triagle_fan code" src="https://github.com/user-attachments/assets/57ccfe17-bd19-4c04-9f2f-59f3799b796a" />
   
   hasil = <img width="601" height="431" alt="triagle_fan" src="https://github.com/user-attachments/assets/b954fe90-b1b6-4c3f-89b1-9ab0ac2b3be7" />

   b. GL_TRIANGLE_STRIP

   kode
   
   <img width="296" height="511" alt="triagle_strip code" src="https://github.com/user-attachments/assets/ad72c995-01cb-48fb-a667-ad3e127eb142" />
   
   hasil = <img width="600" height="431" alt="triagle_strip" src="https://github.com/user-attachments/assets/9637daf5-5834-4889-841f-b6867d48b646" />

3. GL_QUAD dan GL_QUAD_STRIP
   
   GL_QUADS digunakan untuk membuat segi empat yang terpisah. Setiap 4 vertex = 1 quad (persegi/persegi panjang). GL_QUAD_STRIP membuat deretan segi empat yang saling terhubung. Setiap pasangan vertex baru akan menambah satu quad.
   
   a. GL_QUAD

   kode

   <img width="307" height="509" alt="quad code png " src="https://github.com/user-attachments/assets/d258e8a6-3296-4021-95f5-ad1b44be3003" />

   hasil = <img width="602" height="430" alt="quad" src="https://github.com/user-attachments/assets/f9c4061f-ef27-4e98-ac2b-cac8513b570e" />

   b. GL_QUAD_STRIP
   
    kode

   <img width="303" height="502" alt="quad_strip code" src="https://github.com/user-attachments/assets/c0409833-16f5-459a-80ff-a0eca0b1ce12" />

   hasil = <img width="601" height="430" alt="quad_strip" src="https://github.com/user-attachments/assets/f53d7187-3469-4fa8-aba7-e20bf296418d" />

4. GAMBAR KUBUS BERTINGKAT

   kode

   <img width="248" height="483" alt="objek kubus code" src="https://github.com/user-attachments/assets/26695e57-a4d4-4fe4-87b4-2628939629f2" />

   hasil = <img width="600" height="431" alt="objek kubus" src="https://github.com/user-attachments/assets/4d3d35d2-1bbb-4f5b-9bea-90f7d1a1599b" />













   

