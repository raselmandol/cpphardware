#include <iostream>
#include <dshow.h>

int main() {
    //Initialize the COM library
    CoInitialize(NULL);

    //Create the Capture Graph Builder
    IGraphBuilder* pGraphBuilder = NULL;
    ICaptureGraphBuilder2* pCaptureGraphBuilder = NULL;
    
    HRESULT hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, (void**)&pCaptureGraphBuilder);
    if (SUCCEEDED(hr)) {
        hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&pGraphBuilder);
        if (SUCCEEDED(hr)) {
            //Initialize the graph
            pCaptureGraphBuilder->SetFiltergraph(pGraphBuilder);
            
            //Add a video capture device filter
            IBaseFilter* pSource = NULL;
            hr = pGraphBuilder->AddSourceFilter(L"your_webcam_device_name", L"Source Filter", &pSource);
            if (SUCCEEDED(hr)) {
                //Render the video output
                hr = pCaptureGraphBuilder->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video, pSource, NULL, NULL);
                if (SUCCEEDED(hr)) {
                    //Control your webcam here
                    std::cout << "Webcam initialized and rendering." << std::endl;
                    //Add your webcam control code here
                    //For example, capturing frames, setting parameters, etc.

                    pSource->Release();
                }
            }
        }
    }
    pGraphBuilder->Release();
    pCaptureGraphBuilder->Release();
    CoUninitialize();

    return 0;
}
