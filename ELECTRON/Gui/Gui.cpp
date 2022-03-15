#include "Gui/Gui.h"



Gui::MyGui::MyGui(GLFWwindow* window)
{
	
	m_window = (GLFWwindow*)window;

}


void Gui::MyGui::NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

}

void Gui::MyGui::Setup()
{
	const char* glsl_version = "#version 130";
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();
    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);
}

void Gui::MyGui::Render()
{


    //static bool opt_fullscreen = true;
    //static bool opt_padding = false;
    //static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    //// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    //// because it would be confusing to have two docking targets within each others.
    //ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    //if (opt_fullscreen)
    //{
    //    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    //    ImGui::SetNextWindowPos(viewport->WorkPos);
    //    ImGui::SetNextWindowSize(viewport->WorkSize);
    //    ImGui::SetNextWindowViewport(viewport->ID);
    //    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    //    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    //    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    //    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    //}
    //else
    //{
    //    dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    //}

    //// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
    //// and handle the pass-thru hole, so we ask Begin() to not render a background.
    //if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
    //    window_flags |= ImGuiWindowFlags_NoBackground;

    //// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    //// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    //// all active windows docked into it will lose their parent and become undocked.
    //// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    //// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    //if (!opt_padding)
    //    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    //ImGui::Begin("ELECTRON", nullptr, window_flags);
    //if (!opt_padding)
    //    ImGui::PopStyleVar();

    //if (opt_fullscreen)
    //    ImGui::PopStyleVar(2);

    //// Submit the DockSpace
    //ImGuiIO& io = ImGui::GetIO();
    //if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    //{
    //    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    //    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    //}

    //if (ImGui::BeginMenuBar())
    //{
    //    if (ImGui::BeginMenu("Options"))
    //    {
    //        // Disabling fullscreen would allow the window to be moved to the front of other windows,
    //        // which we can't undo at the moment without finer window depth/z control.
    //        ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
    //        ImGui::MenuItem("Padding", NULL, &opt_padding);
    //        ImGui::Separator();

    //        if (ImGui::MenuItem("Flag: NoSplit", "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
    //        if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
    //        if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
    //        if (ImGui::MenuItem("Flag: AutoHideTabBar", "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
    //        if (ImGui::MenuItem("Flag: PassthruCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) { dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
    //        ImGui::Separator();

    //        ImGui::EndMenu();
    //    }
    //   
    //    ImGui::EndMenuBar();


    //    //my stuf here

        /*ImGui::Begin("Settings");
        ImGui::Button("hello");
        static float value = 0.0f;
        ImGui::DragFloat("value", &value);
        ImGui::End();*/














    //}

    //ImGui::End();



























    //==============
    //render imgui==
    //==============
     ImGui::Render();
     ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
     // Update and Render additional Platform Windows
     // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
     //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
     
     //if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
     //{
         GLFWwindow* backup_current_context = glfwGetCurrentContext();
         ImGui::UpdatePlatformWindows();
         ImGui::RenderPlatformWindowsDefault();
         glfwMakeContextCurrent(backup_current_context);
     //}






}
