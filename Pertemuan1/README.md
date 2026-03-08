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
      void GarisStrip(void)
      {
          glClear(GL_COLOR_BUFFER_BIT);
          glColor3f(1.0f, 0.0f, 0.0f);
          glBegin(GL_LINE_STRIP);
              glVertex3f(-0.20, -0.10, 0.0);
              glVertex3f(-0.10, 0.10, 0.0);
              glVertex3f(0.00, -0.10, 0.0);
              glVertex3f(0.10, 0.10, 0.0);
              glVertex3f(0.20, -0.10, 0.0);
          glEnd();
          glFlush();
      }
      hasil = <img width="639" height="496" alt="line_strip" src="https://github.com/user-attachments/assets/3e26e812-4ec2-4377-8e15-0efea876c3dc" />

   b. GL_LINE_LOOP
      void display(void)
      {
         glClear(GL_COLOR_BUFFER_BIT);
         glColor3f(1.0, 1.0, 1.0); 
         glBegin(GL_LINE_LOOP);
            glVertex2f(-0.5, -0.5);
            glVertex2f(0.5, -0.5);
            glVertex2f(0.5, 0.5);
            glVertex2f(-0.5, 0.5);
         glEnd();
         glFlush();
      }
      hasil = <img width="600" height="432" alt="line_loop" src="https://github.com/user-attachments/assets/542eef62-ad49-434f-8d99-47503a6c9fab" />



   

