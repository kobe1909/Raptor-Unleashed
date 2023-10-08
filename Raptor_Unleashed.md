# Raptor Unleashed Project

- Mesh
    - importers for obj, ..
    - meshdata + objects
        - buffer object
        - index object
        - array object
          
- Material
    - implements shader
    - aplies uniforms

- Engine (main file) 
    🠊 Runs the application from the main file

- GameObject
    - Transform (needed) 🠊 Vector3
        - Local and world position
        - Local and world angles (Euler & Quaternion)
        - Local and World scale
        + Getters and Setters
        + Moving in all directions
    - Component array (all components must be set in advance) 🠊 activate or deactivate components when needed

---
**Components:**
- BaseComponent
  - Awake()
  - Start()
  - Update()
  - LateUpdate()
  - Destroy()
  - Bind() 🠊 For meshes, material, ...
- MeshComponent
- MaterialComponent
- Renderer 🠊 Renders the object using the gameobjects material and mesh

---
**Math:**
🠊 all methods and types in a Math class
- Vectors (2, 3, 4)
      VectorN 
      xyzw 
      rgba
