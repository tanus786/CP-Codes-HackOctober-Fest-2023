using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR;

public class VrOFF : MonoBehaviour
{
    // Start is called before the first frame update
    public void VROFf()
    {
        XRSettings.enabled = false;
    }
    public void VRONn()
    {
        XRSettings.enabled = true;
    }
}
