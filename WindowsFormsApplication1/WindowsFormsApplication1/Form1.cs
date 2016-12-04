﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private bool isPlayerOne = true;
        public Form1()
        {
            InitializeComponent();
            
        }
        

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {
            
            

        }

        private void button1_Click(object sender, EventArgs e)
        {

            bool hasControl = false;
            int i = 6;
            while (hasControl == false && i >= 0)
            {
                if (isPlayerOne)
                {

                    if (tableLayoutPanel1.GetControlFromPosition(0, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 0, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }
                else
                {
                    isPlayerOne = true;
                    if (tableLayoutPanel1.GetControlFromPosition(0, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 0, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }



            }
        }
        private Label makeNewLabel(bool isPlayerOne)
        {
            Label label1 = new Label();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Cursor = System.Windows.Forms.Cursors.Default;
            label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 40F,FontStyle.Regular);
            
            label1.Location = new System.Drawing.Point(4, 1);
            label1.Name = "label1";
            label1.Size = new System.Drawing.Size(60, 63);
            label1.TabIndex = 3;
            label1.Text = "O";
            if (isPlayerOne)
            {
                label1.ForeColor = Color.Crimson;
            }
            else
            {
                label1.ForeColor = Color.Gold;
            }
            return label1;
        }

        private void button2_Click(object sender, EventArgs e)
        {

            bool hasControl = false;
            int i = 6;
            while (hasControl == false && i >= 0)
            {
                if (isPlayerOne)
                {

                    if (tableLayoutPanel1.GetControlFromPosition(1, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 1, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }
                else
                {
                    isPlayerOne = true;
                    if (tableLayoutPanel1.GetControlFromPosition(1, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 1, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }



            }
        }

        private void button3_Click(object sender, EventArgs e)
        {

            bool hasControl = false;
            int i = 6;
            while (hasControl == false && i >= 0)
            {
                if (isPlayerOne)
                {

                    if (tableLayoutPanel1.GetControlFromPosition(2, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 2, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }
                else
                {
                    isPlayerOne = true;
                    if (tableLayoutPanel1.GetControlFromPosition(2, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 2, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }



            }
        }

        private void button4_Click(object sender, EventArgs e)
        {

            bool hasControl = false;
            int i = 6;
            while (hasControl == false && i >= 0)
            {
                if (isPlayerOne)
                {

                    if (tableLayoutPanel1.GetControlFromPosition(3, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 3, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }
                else
                {
                    isPlayerOne = true;
                    if (tableLayoutPanel1.GetControlFromPosition(3, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 3, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }



            }
        }

        private void button5_Click(object sender, EventArgs e)
        {

            bool hasControl = false;
            int i = 6;
            while (hasControl == false && i >= 0)
            {
                if (isPlayerOne)
                {

                    if (tableLayoutPanel1.GetControlFromPosition(4, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 4, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }
                else
                {
                    isPlayerOne = true;
                    if (tableLayoutPanel1.GetControlFromPosition(4, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 4, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }



            }
        }

        private void button6_Click(object sender, EventArgs e)
        {

            bool hasControl = false;
            int i = 6;
            while (hasControl == false && i >= 0)
            {
                if (isPlayerOne)
                {

                    if (tableLayoutPanel1.GetControlFromPosition(5, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 5, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }
                else
                {
                    isPlayerOne = true;
                    if (tableLayoutPanel1.GetControlFromPosition(5, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 5, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }



            }
        }

        private void button7_Click(object sender, EventArgs e)
        {

            bool hasControl = false;
            int i = 6;
            while (hasControl == false && i >= 0)
            {
                if (isPlayerOne)
                {

                    if (tableLayoutPanel1.GetControlFromPosition(6, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 6, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }
                else
                {
                    isPlayerOne = true;
                    if (tableLayoutPanel1.GetControlFromPosition(6, i) == null)
                    {
                        this.tableLayoutPanel1.Controls.Add(makeNewLabel(isPlayerOne), 6, i);
                        hasControl = true;

                        isPlayerOne = false;

                    }
                    else
                    {
                        i--;
                    }
                }



            }
        }
    }

}
