// generated by Fast Light User Interface Designer (fluid) version 1.0302

#include "ui.h"

void laserApp::cb_open_button_i(Fl_Button*, void*) {
  log("Choose");
log("Choose files(*.txt, *.pcd)");
std::vector<std::string> file_paths;
Fl_File_Chooser chooser(".",                        // directory
                            "*",                        // filter
                            Fl_File_Chooser::MULTI,     // chooser type
                            "Choose Point Cloud Files");        // title
    chooser.show();
    while(chooser.shown())
        { Fl::wait(); }

    // User hit cancel?
    if ( chooser.value() == NULL )
        { log("User hit 'Cancel'"); open_button -> label("Open Cloud Files..."); return; }

	std::string single_choice(chooser.value());
	file_paths.push_back(single_choice);
    // Multiple files? Show all of them
    if ( chooser.count() > 1 ) {
        for ( int t=1; t<=chooser.count(); t++ ) {
            fprintf(stderr, " VALUE[%d]: '%s'\n", t, chooser.value(t));
            std::string temp_path(chooser.value(t));
            file_paths.push_back(temp_path);
        }
    }


log("Opening Files....");
this->cloud_model. open_files(file_paths);

open_button -> label("Open Cloud Files...");
log("File Opened Done.");
}
void laserApp::cb_open_button(Fl_Button* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_open_button_i(o,v);
}

void laserApp::cb_Register_i(Fl_Button*, void*) {
  log("Registering....");
cloud_model.registration(g_bottom, g_top, g_leaf_size, g_max_icp);
std::stringstream ss;
log(ss.str().c_str());
}
void laserApp::cb_Register(Fl_Button* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_Register_i(o,v);
}

void laserApp::cb_Noise_i(Fl_Button*, void*) {
  log("Noise Removing....");
int count = cloud_model.noise_cancel(this->g_meank, this->g_stddev);
std::stringstream ss;
ss<<"Removed "<<count<<" Points.";
log(ss.str().c_str());
}
void laserApp::cb_Noise(Fl_Button* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_Noise_i(o,v);
}

void laserApp::cb_Segment_i(Fl_Button*, void*) {
  log("Clustering....");
cloud_model.segmentation(g_leaf_size, g_seg_max_iter, g_dist, g_cluter_tol, g_min_clu, g_max_clu);
std::stringstream ss;
ss<<"Segmenataion Done.";
log(ss.str().c_str());
}
void laserApp::cb_Segment(Fl_Button* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_Segment_i(o,v);
}

void laserApp::cb_Save_i(Fl_Button*, void*) {
  log("Choose");

std::string file_path;
Fl_File_Chooser chooser(".",                        // directory
                            "*",                        // filter
                            Fl_File_Chooser::CREATE,     // chooser type
                            "PCD File SAVE");        // title
    chooser.show();
    while(chooser.shown())
        { Fl::wait(); }

    // User hit cancel?
    if ( chooser.value() == NULL )
        { log("User hit 'Cancel'"); 
        return; }
	else
	{
	std::string temp(chooser.value());
	file_path = temp;
	}

log("Saving....");
cloud_model.save_files(file_path);
std::stringstream ss;
ss<<"Save Done.";
log(ss.str().c_str());
}
void laserApp::cb_Save(Fl_Button* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_Save_i(o,v);
}

void laserApp::cb_Visualize_i(Fl_Button*, void*) {
  cloud_model.visualize_cloud();
}
void laserApp::cb_Visualize(Fl_Button* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_Visualize_i(o,v);
}

void laserApp::cb_meank_i(Fl_Spinner*, void*) {
  this->g_meank = meank->value();
std::string temp = "set MeanK value to ";
std::stringstream ss;
ss << temp << g_meank;
log(ss.str().c_str());
}
void laserApp::cb_meank(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_meank_i(o,v);
}

void laserApp::cb_stddev_i(Fl_Spinner*, void*) {
  this->g_stddev = (float) stddev->value();
std::string temp = "set stddev value to ";
std::stringstream ss;
ss << temp << g_stddev;
log(ss.str().c_str());
}
void laserApp::cb_stddev(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_stddev_i(o,v);
}

void laserApp::cb_bottom_i(Fl_Spinner*, void*) {
  this->g_bottom = (float) bottom->value();
std::string temp = "set min cut value to ";
std::stringstream ss;
ss << temp << g_bottom;
log(ss.str().c_str());
}
void laserApp::cb_bottom(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_bottom_i(o,v);
}

void laserApp::cb_top_i(Fl_Spinner*, void*) {
  this->g_top = (float) top->value();
std::string temp = "set top cut value to ";
std::stringstream ss;
ss << temp << g_top;
log(ss.str().c_str());
}
void laserApp::cb_top(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_top_i(o,v);
}

void laserApp::cb_leaf_size_i(Fl_Spinner*, void*) {
  this->g_leaf_size = (float) leaf_size->value();
std::string temp = "set leaf size value to ";
std::stringstream ss;
ss << temp << g_leaf_size;
log(ss.str().c_str());
}
void laserApp::cb_leaf_size(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_leaf_size_i(o,v);
}

void laserApp::cb_max_icp_i(Fl_Spinner*, void*) {
  this->g_max_icp =  max_icp->value();
std::string temp = "set max icp iter value to ";
std::stringstream ss;
ss << temp << g_max_icp;
log(ss.str().c_str());
}
void laserApp::cb_max_icp(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_max_icp_i(o,v);
}

void laserApp::cb_voxel_leaf_i(Fl_Spinner*, void*) {
  this->g_voxel_leaf = (float)voxel_leaf->value();
std::string temp = "set voxel leaf value to ";
std::stringstream ss;
ss << temp << g_voxel_leaf;
log(ss.str().c_str());
}
void laserApp::cb_voxel_leaf(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_voxel_leaf_i(o,v);
}

void laserApp::cb_seg_max_iter_i(Fl_Spinner*, void*) {
  this->g_seg_max_iter = (float)seg_max_iter->value();
std::string temp = "set seg max iter value to ";
std::stringstream ss;
ss << temp << g_seg_max_iter;
log(ss.str().c_str());
}
void laserApp::cb_seg_max_iter(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_seg_max_iter_i(o,v);
}

void laserApp::cb_dist_i(Fl_Spinner*, void*) {
  this->g_dist = (int)dist->value();
std::string temp = "set distance thresh to ";
std::stringstream ss;
ss << temp << g_dist;
log(ss.str().c_str());
}
void laserApp::cb_dist(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_dist_i(o,v);
}

void laserApp::cb_cluster_tol_i(Fl_Spinner*, void*) {
  this->g_cluter_tol = (double)cluster_tol->value();
std::string temp = "set cluster tol value to ";
std::stringstream ss;
ss << temp << g_cluter_tol;
log(ss.str().c_str());
}
void laserApp::cb_cluster_tol(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_cluster_tol_i(o,v);
}

void laserApp::cb_min_clu_i(Fl_Spinner*, void*) {
  this->g_min_clu = min_clu->value();
std::string temp = "set min clusters value to ";
std::stringstream ss;
ss << temp << g_min_clu;
log(ss.str().c_str());
}
void laserApp::cb_min_clu(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_min_clu_i(o,v);
}

void laserApp::cb_max_clu_i(Fl_Spinner*, void*) {
  this->g_max_clu = max_clu->value();
std::string temp = "set max clusters value to ";
std::stringstream ss;
ss << temp << g_max_clu;
log(ss.str().c_str());
}
void laserApp::cb_max_clu(Fl_Spinner* o, void* v) {
  ((laserApp*)(o->parent()->user_data()))->cb_max_clu_i(o,v);
}

laserApp::laserApp() {
  { basicWindow = new Fl_Double_Window(225, 520, "Laserviewer Control Panel");
    basicWindow->user_data((void*)(this));
    { new Fl_Text_Display(45, 30, 135, 5, "Laser Viewer");
    } // Fl_Text_Display* o
    { new Fl_Text_Display(40, 443, 150, 5, "CAU");
    } // Fl_Text_Display* o
    { open_button = new Fl_Button(15, 49, 200, 35, "Open Cloud Files...");
      open_button->labeltype(FL_EMBOSSED_LABEL);
      open_button->callback((Fl_Callback*)cb_open_button);
    } // Fl_Button* open_button
    { Fl_Button* o = new Fl_Button(15, 116, 200, 35, "Register Clouds");
      o->labeltype(FL_EMBOSSED_LABEL);
      o->callback((Fl_Callback*)cb_Register);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(15, 184, 200, 35, "Noise Cancel Clouds");
      o->labeltype(FL_EMBOSSED_LABEL);
      o->callback((Fl_Callback*)cb_Noise);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(15, 251, 200, 35, "Segment Cloud");
      o->labeltype(FL_EMBOSSED_LABEL);
      o->callback((Fl_Callback*)cb_Segment);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(15, 319, 200, 35, "Save Cloud Files...");
      o->labeltype(FL_EMBOSSED_LABEL);
      o->callback((Fl_Callback*)cb_Save);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(15, 381, 200, 35, "Visualize Current Clouds");
      o->labeltype(FL_EMBOSSED_LABEL);
      o->callback((Fl_Callback*)cb_Visualize);
    } // Fl_Button* o
    { logWidget = new Fl_Text_Display(10, 501, 210, 10, "Welcome.");
      logWidget->color((Fl_Color)96);
      logWidget->selection_color((Fl_Color)14);
      logWidget->labelfont(4);
      logWidget->labelsize(12);
      logWidget->labelcolor((Fl_Color)59);
    } // Fl_Text_Display* logWidget
    basicWindow->end();
  } // Fl_Double_Window* basicWindow
  { advancedWindow = new Fl_Double_Window(350, 725, "Laserviewer Advanced Control");
    advancedWindow->user_data((void*)(this));
    { new Fl_Text_Display(102, 30, 135, 4, "Advanced Values");
    } // Fl_Text_Display* o
    { meank = new Fl_Spinner(225, 52, 110, 37, "Noise Cancel MeanK");
      meank->maximum(450);
      meank->value(50);
      meank->callback((Fl_Callback*)cb_meank);
      this->g_meank = meank->value();
    } // Fl_Spinner* meank
    { stddev = new Fl_Spinner(225, 106, 110, 37, "Noise Cancel Stddev");
      stddev->type(1);
      stddev->minimum(0.001);
      stddev->maximum(20);
      stddev->step(0.01);
      stddev->callback((Fl_Callback*)cb_stddev);
      this->g_stddev = (float) stddev->value();
    } // Fl_Spinner* stddev
    { bottom = new Fl_Spinner(225, 161, 110, 37, "Registration Bottom Cut");
      bottom->type(1);
      bottom->minimum(-5000);
      bottom->step(20);
      bottom->value(100);
      bottom->callback((Fl_Callback*)cb_bottom);
      this->g_bottom = (float) bottom->value();
    } // Fl_Spinner* bottom
    { top = new Fl_Spinner(225, 215, 110, 37, "Registration Top Cut");
      top->type(1);
      top->minimum(-6000);
      top->maximum(26000);
      top->step(20);
      top->value(8000);
      top->callback((Fl_Callback*)cb_top);
      this->g_top = (float) top->value();
    } // Fl_Spinner* top
    { leaf_size = new Fl_Spinner(225, 270, 110, 37, "Registration Leaf Size");
      leaf_size->type(1);
      leaf_size->maximum(500);
      leaf_size->step(0.1);
      leaf_size->value(80);
      leaf_size->callback((Fl_Callback*)cb_leaf_size);
      this->g_leaf_size = (float) leaf_size->value();
    } // Fl_Spinner* leaf_size
    { max_icp = new Fl_Spinner(225, 325, 110, 37, "Registration Max ICP Iteration #");
      max_icp->maximum(450);
      max_icp->value(50);
      max_icp->callback((Fl_Callback*)cb_max_icp);
      this->g_max_icp =  max_icp->value();
    } // Fl_Spinner* max_icp
    { voxel_leaf = new Fl_Spinner(225, 379, 110, 37, "Segmentation Voxel Grid Size");
      voxel_leaf->type(1);
      voxel_leaf->maximum(450);
      voxel_leaf->step(0.1);
      voxel_leaf->value(10);
      voxel_leaf->callback((Fl_Callback*)cb_voxel_leaf);
      this->g_voxel_leaf = (float)voxel_leaf->value();
    } // Fl_Spinner* voxel_leaf
    { seg_max_iter = new Fl_Spinner(225, 434, 110, 37, "Segmentation Max Iteration #");
      seg_max_iter->maximum(450);
      seg_max_iter->value(256);
      seg_max_iter->callback((Fl_Callback*)cb_seg_max_iter);
      this->g_seg_max_iter = (float)seg_max_iter->value();
    } // Fl_Spinner* seg_max_iter
    { dist = new Fl_Spinner(225, 489, 110, 37, "Segmentation Distance Thresh");
      dist->maximum(25000);
      dist->value(200);
      dist->callback((Fl_Callback*)cb_dist);
      this->g_dist = dist->value();
    } // Fl_Spinner* dist
    { cluster_tol = new Fl_Spinner(225, 543, 110, 37, "Segmentation Cluster Tolerance");
      cluster_tol->type(1);
      cluster_tol->maximum(50000);
      cluster_tol->step(0.1);
      cluster_tol->value(200);
      cluster_tol->callback((Fl_Callback*)cb_cluster_tol);
      this->g_cluter_tol = (double)cluster_tol->value();
    } // Fl_Spinner* cluster_tol
    { min_clu = new Fl_Spinner(225, 598, 110, 37, "Segmentation Min Cluster Size");
      min_clu->maximum(25000);
      min_clu->value(100);
      min_clu->callback((Fl_Callback*)cb_min_clu);
      this->g_min_clu = min_clu->value();
    } // Fl_Spinner* min_clu
    { max_clu = new Fl_Spinner(225, 653, 110, 37, "Segmentation Max Cluster Size");
      max_clu->maximum(600000);
      max_clu->value(25000);
      max_clu->callback((Fl_Callback*)cb_max_clu);
      this->g_max_clu = max_clu->value();
    } // Fl_Spinner* max_clu
    advancedWindow->end();
  } // Fl_Double_Window* advancedWindow
  printf("Hello, World!\n");
}

void laserApp::log(const char* text) {
  logWidget->label("");
  logWidget->label(text);
}

int main(int argc, char **argv) {
  laserApp app;
  app.basicWindow->show(argc, argv);
  app.advancedWindow->show(argc, argv);
  return Fl::run();
}
