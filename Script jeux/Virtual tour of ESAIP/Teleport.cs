using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Teleport : MonoBehaviour
{
    public PlayerCC targetscript;

    public GameObject TPA;
    public GameObject TPB;
    public GameObject TPC;
    public GameObject TPE;

    public void BATA()
    {
        targetscript.Spawn(TPA.transform.position, 110, 0);
    }

    public void BATB()
    {
        targetscript.Spawn(TPB.transform.position ,-60, 0);
    }

    public void BATC()
    {
        targetscript.Spawn(TPC.transform.position, -150, -4);
    }

    public void BATE()
    {
        targetscript.Spawn(TPE.transform.position, 158, -4);
    }
}