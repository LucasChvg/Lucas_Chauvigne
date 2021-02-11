using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DayNight : MonoBehaviour
{
    Light sun;

    public float speed = 10f;

    // Start is called before the first frame update
    void Start()
    {
        sun = GetComponent<Light>();    
    }

    // Update is called once per frame
    void Update()
    {
        sun.transform.Rotate(Vector3.right * speed * Time.deltaTime);
    }
}
