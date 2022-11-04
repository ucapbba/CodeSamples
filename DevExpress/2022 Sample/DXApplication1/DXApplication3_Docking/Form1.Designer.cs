
using DevExpress.XtraBars;

namespace DXApplication3_Docking
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.dockManager1 = new DevExpress.XtraBars.Docking.DockManager(this.components);
            this.dockPanel2 = new DevExpress.XtraBars.Docking.DockPanel();
            this.dockPanel2_Container = new DevExpress.XtraBars.Docking.ControlContainer();
            this.dockPanel4 = new DevExpress.XtraBars.Docking.DockPanel();
            this.dockPanel4_Container = new DevExpress.XtraBars.Docking.ControlContainer();
            this.dockPanel3 = new DevExpress.XtraBars.Docking.DockPanel();
            this.dockPanel3_Container = new DevExpress.XtraBars.Docking.ControlContainer();
            ((System.ComponentModel.ISupportInitialize)(this.dockManager1)).BeginInit();
            this.dockPanel2.SuspendLayout();
            this.dockPanel4.SuspendLayout();
            this.dockPanel3.SuspendLayout();
            this.dockPanel3_Container.SuspendLayout();
            this.SuspendLayout();
            // 
            // dockManager1
            // 
            this.dockManager1.Form = this;
            this.dockManager1.RootPanels.AddRange(new DevExpress.XtraBars.Docking.DockPanel[] {
            this.dockPanel4,
            this.dockPanel2,
            this.dockPanel3});
            this.dockManager1.TopZIndexControls.AddRange(new string[] {
            "DevExpress.XtraBars.BarDockControl",
            "DevExpress.XtraBars.StandaloneBarDockControl",
            "System.Windows.Forms.MenuStrip",
            "System.Windows.Forms.StatusStrip",
            "System.Windows.Forms.StatusBar",
            "DevExpress.XtraBars.Ribbon.RibbonStatusBar",
            "DevExpress.XtraBars.Ribbon.RibbonControl",
            "DevExpress.XtraBars.Navigation.OfficeNavigationBar",
            "DevExpress.XtraBars.Navigation.TileNavPane",
            "DevExpress.XtraBars.TabFormControl",
            "DevExpress.XtraBars.FluentDesignSystem.FluentDesignFormControl",
            "DevExpress.XtraBars.ToolbarForm.ToolbarFormControl"});
      
            // 
            // dockPanel2
            // 
            this.dockPanel2.Controls.Add(this.dockPanel2_Container);
            this.dockPanel2.Dock = DevExpress.XtraBars.Docking.DockingStyle.Top;
            this.dockPanel2.FloatVertical = true;
            this.dockPanel2.ID = new System.Guid("ee778034-fb27-4211-9bd4-a544bb166460");
            this.dockPanel2.Location = new System.Drawing.Point(0, 62);
            this.dockPanel2.Name = "dockPanel2";
            this.dockPanel2.OriginalSize = new System.Drawing.Size(810, 200);
            this.dockPanel2.Size = new System.Drawing.Size(810, 200);
            this.dockPanel2.Text = "dockPanel2";
            // 
            // dockPanel2_Container
            // 
            this.dockPanel2_Container.Location = new System.Drawing.Point(3, 26);
            this.dockPanel2_Container.Name = "dockPanel2_Container";
            this.dockPanel2_Container.Size = new System.Drawing.Size(804, 170);
            this.dockPanel2_Container.TabIndex = 0;
            // 
            // dockPanel4
            // 
            this.dockPanel4.Controls.Add(this.dockPanel4_Container);
            this.dockPanel4.Dock = DevExpress.XtraBars.Docking.DockingStyle.Bottom;
            this.dockPanel4.FloatVertical = true;
            this.dockPanel4.ID = new System.Guid("15d1d681-0daf-483a-bfa7-c691fe6ba45d");
            this.dockPanel4.Location = new System.Drawing.Point(0, 233);
            this.dockPanel4.Name = "dockPanel4";
            this.dockPanel4.OriginalSize = new System.Drawing.Size(200, 87);
            this.dockPanel4.Size = new System.Drawing.Size(810, 87);
            this.dockPanel4.Text = "dockPanel4";
            // 
            // dockPanel4_Container
            // 
            this.dockPanel4_Container.Location = new System.Drawing.Point(3, 27);
            this.dockPanel4_Container.Name = "dockPanel4_Container";
            this.dockPanel4_Container.Size = new System.Drawing.Size(804, 57);
            this.dockPanel4_Container.TabIndex = 0;
            // 
            // dockPanel3
            // 
            this.dockPanel3.Controls.Add(this.dockPanel3_Container);
            this.dockPanel3.Dock = DevExpress.XtraBars.Docking.DockingStyle.Fill;
            this.dockPanel3.FloatSize = new System.Drawing.Size(200, 197);
            this.dockPanel3.ID = new System.Guid("134b170d-78f5-42ed-a082-b4d5f66b6e48");
            this.dockPanel3.Location = new System.Drawing.Point(0, 262);
            this.dockPanel3.Name = "dockPanel3";
            this.dockPanel3.OriginalSize = new System.Drawing.Size(668, 200);
            this.dockPanel3.Size = new System.Drawing.Size(810, 0);
            this.dockPanel3.Text = "dockPanel3";
            // 
            // dockPanel3_Container
            // 
            this.dockPanel3_Container.Location = new System.Drawing.Point(3, -8);
            this.dockPanel3_Container.Name = "dockPanel3_Container";
            this.dockPanel3_Container.Size = new System.Drawing.Size(804, 0);
            this.dockPanel3_Container.TabIndex = 0;
            // 
            // standaloneBarDockControl3
            // 
   
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(810, 360);
            this.Controls.Add(this.dockPanel3);
            this.Controls.Add(this.dockPanel2);
            this.Controls.Add(this.dockPanel4);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dockManager1)).EndInit();
            this.dockPanel2.ResumeLayout(false);
            this.dockPanel4.ResumeLayout(false);
            this.dockPanel3.ResumeLayout(false);
            this.dockPanel3_Container.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        //private DevExpress.XtraBars.Docking.ControlContainer dockPanel1_Container;
        //private DevExpress.XtraBars.Docking.ControlContainer dockPanel2_Container;
        #endregion

        private DevExpress.XtraBars.Docking.DockManager dockManager1;
        private DevExpress.XtraBars.Docking.DockPanel dockPanel2;
        private DevExpress.XtraBars.Docking.ControlContainer dockPanel2_Container;
        private DevExpress.XtraBars.Docking.DockPanel dockPanel3;
        private DevExpress.XtraBars.Docking.ControlContainer dockPanel3_Container;
        private DevExpress.XtraBars.Docking.DockPanel dockPanel4;
        private DevExpress.XtraBars.Docking.ControlContainer dockPanel4_Container;
    }
}

